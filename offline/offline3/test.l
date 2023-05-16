
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

int line_count=1;
int error=0;

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


%}



digit [0-9]
letter [A-Za-z]
delim [ \t\r\f\v]
newline \n
ws [delim]+
id (_|{letter})(_|{letter}|{digit})*
integer {digit}+
number {digit}*(\.{digit}+)?((E|e)[+-]?{digit}+)?
ADDOP [+-] 
MULOP [*/%]

%%

{delim}+	{}
{ws} {}
{newline} {line_count++;}

"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"int" {return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"char" {return CHAR;}
"return" {return RETURN;}
"void" {return VOID;}
"main"	{return MAIN;}
"println"	{return PRINTLN;}

{ADDOP} { 
			SymbolInfo *s= new  SymbolInfo(yytext, (char *)"ADDOP");
			yylval = (YYSTYPE)s;
			return ADDOP;
		}



{MULOP}	{
			SymbolInfo *s= new  SymbolInfo(yytext, (char *)"MULOP");
			yylval = (YYSTYPE)s;
			return MULOP;
		}


"=" 	{return ASSIGNOP;}

">" |
"<" |
">=" |
"<=" |
"==" |
"!=" {
		SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RELOP");
		yylval = (YYSTYPE)s;
		return RELOP;
	}

"&&"	|
"||"	{
			SymbolInfo *s= new  SymbolInfo(yytext, (char *)"LOGICOP");
			yylval = (YYSTYPE)s;
			return LOGICOP;
		}
"!"		{	return NOT; }


";" 	{ return SEMICOLON;}
"," 	{return COMMA;}
"(" 	{return LPAREN;}
")" 	{return RPAREN;}
"{" 	{return LCURL;}
"}" 	{return RCURL;}
"[" 	{return LTHIRD;}
"]" 	{return RTHIRD;}
"++" 	{return INCOP;}
"--" 	{return DECOP;}



{integer}	{
				SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CONST_INT");
				yylval = (YYSTYPE)s;
				return CONST_INT;
			}
{number} 	{	
				SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CONST_FLOAT");
				yylval = (YYSTYPE)s;
				return CONST_FLOAT; 
			}
{id} 		{	 
				
				SymbolInfo *s= table->lookup(yytext);
				if(s==NULL)
				{					
					s= new SymbolInfo(yytext, (char *)"ID");
				}
				yylval = (YYSTYPE)s;
							
				return ID;
			}


%%

int yywrap(void)
{
	return 1;
}






