%option noyywrap
%{
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<bits/stdc++.h>
#include "1805063_symbol_table.h"

#include "y.tab.h"



using namespace std;

//extern YYSTYPE yylval;
//extern SymbolTable *table;
void yyerror(char *);

extern int line_count;
extern int error;

string getConstChar(string s){
    //cout<<"ttadgcgb "<<s<<endl;
    string res="";
    //cout<<s<<"fandkjf"<<endl;
    if(s.compare("\\t")==0){
        //cout<<"qdhfkqhh"<<endl;
        res="\t";
    }
    else if(s.compare("\\n")==0){
        res="\n";
    }
    else if(s.compare("\\a")==0){
        res="\a";
    }
    else if(s.compare("\\\"")==0){
        res="\"";
    }
     else if(s.compare("\\\'")==0){
        res="\'";
    }
     else if(s.compare("\\")==0){
        res="\\";
    }
    else if(s.compare("\\f")==0){
        res="\f";
    }
    else if(s.compare("\\r")==0){
        res="\r";
    }
    else if(s.compare("\\b")==0){
        res="\b";
    }

    else if(s.compare("\\v")==0){
        res="\v";
    }
    else if(s.compare("\\0")==0){
        res="\0";
    }
    else{
        res=s;
    }
    return res;

    
    
    
}
void errorlex(string s,int a){
    error++;
    ofstream f2;
    f2.open("1805063_error.txt",ios::app);
    f2<<"line_no: "<<a<<" "<<s<<endl;
    
    f2.close();
}


%}



digit [0-9]
digits {digit}+
letter [a-zA-Z]
alphabet {letter}|_
s_char [\"nt\'afrbvo]
whitespace [ \t\v\f\r]+

alphanum {alphabet}|{digit}
newline ([\r]?)([\n])





%%

{whitespace}	{}
{newline} {line_count++;}










"if" {//addkeywords("IF",yytext);
    smbol_info* s = new smbol_info(yytext, "IF");
    
    yylval.symbol = s;
                
    return IF;
    }
"for" {
    smbol_info* s = new smbol_info(yytext, "FOR");
    
    yylval.symbol = s;
                
    return FOR;//addkeywords("FOR",yytext);
    }

"do" { //addkeywords("DO",yytext);
    smbol_info* s = new smbol_info(yytext, "DO");
    
    yylval.symbol = s;
                
    return DO; }
"int" { //addkeywords("INT",yytext);
    smbol_info* s = new smbol_info(yytext, "INT");
    
    yylval.symbol = s;
                
    return INT; }
"float" { smbol_info* s = new smbol_info(yytext, "FLOAT");
    
    yylval.symbol = s;
                
    return FLOAT; }
"void" { smbol_info* s = new smbol_info(yytext, "VOID");
    
    yylval.symbol = s;
                
    return VOID; }

"else" {smbol_info* s = new smbol_info(yytext, "ELSE");
    
    yylval.symbol = s;
                
    return ELSE;}
"while" {smbol_info* s = new smbol_info(yytext, "WHILE");
    
    yylval.symbol = s;
                
    return WHILE;}

"char" {smbol_info* s = new smbol_info(yytext, "CHAR");
    
    yylval.symbol = s;
                
    return CHAR;}

"return" { smbol_info* s = new smbol_info(yytext, "RETURN");
    
    yylval.symbol = s;
                
    return RETURN; }
"println" {smbol_info* s = new smbol_info(yytext, "PRINTLN");
    
    yylval.symbol = s;
                
    return PRINTLN;}

"++" {smbol_info* s = new smbol_info(yytext, "INCOP");
    
    yylval.symbol = s;
                
    return INCOP;}
"--" {smbol_info* s = new smbol_info(yytext, "DECOP");
    
    yylval.symbol = s;
                
    return DECOP;}
"+" {smbol_info* s = new smbol_info(yytext, "ADDOP");
    
    yylval.symbol = s;
                
    return ADDOP;}
"-" {smbol_info* s = new smbol_info(yytext, "ADDOP");
    
    yylval.symbol = s;
                
    return ADDOP;}

"*"|"/"|"%" {smbol_info* s = new smbol_info(yytext, "MULOP");
    
    yylval.symbol = s;
                
    return MULOP;}


">="|"<="|"=="|"!="|">"|"<" {smbol_info* s = new smbol_info(yytext, "RELOP");
    
    yylval.symbol = s;
                
    return RELOP;}

"=" {smbol_info* s = new smbol_info(yytext, "ASSIGNOP");
    
    yylval.symbol = s;
                
    return ASSIGNOP;}
"&&"|"||" {smbol_info* s = new smbol_info(yytext, "LOGICOP");
    
    yylval.symbol = s;
                
    return LOGICOP;}

"!" {smbol_info* s = new smbol_info(yytext, "NOT");
    
    yylval.symbol = s;
                
    return NOT;}
"(" {smbol_info* s = new smbol_info(yytext, "LPAREN");
    
    yylval.symbol = s;
                
    return LPAREN;}
")" {smbol_info* s = new smbol_info(yytext, "RPAREN");
    
    yylval.symbol = s;
                
    return RPAREN;}
"{" {smbol_info* s = new smbol_info(yytext, "LCURL");
    
    yylval.symbol = s;
                
    return LCURL;}
"}" {smbol_info* s = new smbol_info(yytext, "RCURL");
    
    yylval.symbol = s;
                
    return RCURL;}
"[" {smbol_info* s = new smbol_info(yytext, "LTHIRD");
    
    yylval.symbol = s;
                
    return LTHIRD;}
"]" {smbol_info* s = new smbol_info(yytext, "RTHIRD");
    
    yylval.symbol = s;
                
    return RTHIRD;}
"," {smbol_info* s = new smbol_info(yytext, "COMMA");
    
    yylval.symbol = s;
                
    return COMMA;}
";" {smbol_info* s = new smbol_info(yytext, "SEMICOLON");
    
    yylval.symbol = s;
                
    return SEMICOLON;}


{digits} {smbol_info* s = new smbol_info(yytext, "CONST_INT");
    
    yylval.symbol = s;
                
    return CONST_INT;}
({digits})?(\.{digits})?((E|e)[+-]?{digits})? {smbol_info* s = new smbol_info(yytext, "CONST_FLOAT");
    
    yylval.symbol = s;
                
    return CONST_FLOAT;}

({digits})?(\.{digits})+(\.{digits})+((E|e)[+-]?{digits}\.({digits})*)? {
    errorlex(" Too many decimal points ",line_count);
    
}
({digits})?(\.)?({digits})?((E|e)[+-]?({digits})?(\.{digits})+) {
    errorlex(" Ill formed number ",line_count);
}

(\')(\') {
    errorlex(" Empty character constant error ",line_count);
}
(\')({alphanum}){2,}(([ ])({alphanum})*)?(\') {
    errorlex(" Multi character constant error ",line_count);
}

(\')(\\{s_char})?[^\r\n\']* {
    errorlex(" Unfinished character constant ",line_count);
}

([\*+/-](" "|\t)*[=])([\*+/-]*(" "|\t)*[=]*)* {
    errorlex("Syntax error",line_count);
    smbol_info* s = new smbol_info(yytext, "UNRECOGNISED_OP");
    
    yylval.symbol = s;
                
    return UNRECOGNISED_OP;
}





({digits})({alphanum})* {
    errorlex(" : Invalid prefix on ID or invalid suffix on Number ",line_count);
}
({alphabet})({alphanum}*) {
    smbol_info* s = new smbol_info(yytext, "ID");
    
    yylval.symbol = s;
                
    return ID;
    
    }




. {
   errorlex("Unrecognized character",line_count);
}


%%

/*/int yywrap(void)
{
	return 1;
}*/
/*

#!/bin/bash

yacc -d -y 1805063.y
echo 'Generated the parser C file as well the header file'
g++ -w -c -o y.o y.tab.c
echo 'Generated the parser object file'
flex 1805063.l
echo 'Generated the scanner C file'
g++ -w -c -o l.o lex.yy.c
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
echo 'Generated the scanner object file'
#g++ symbol_table.cpp -c
echo 'Generated the symbol table object files'
#g++ symbol_table.o y.o l.o -lfl
g++ y.o l.o -lfl -o out

echo 'All ready, running'
./out input.c

*/






