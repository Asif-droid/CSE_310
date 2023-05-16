%option noyywrap
%x STRINGSTATE
%x MULCOMMENT
%x SINGLECOMMENT
%{
#include<bits/stdc++.h>
#include "SymbolTable.h"
using namespace std;

string teyytext;
SymbolTable stbl;
int line_count=1;
int counterror=0;
string strlex;
 string getConstChar(string st2){
 	if(st2.compare("\\t")==0) st2="\t";
 	else if(st2.compare("\\n")==0) st2="\n";
 	else if(st2.compare("\\")==0) st2="\\";
 	else if(st2.compare("\\\"")==0) st2="\"";
 	else if(st2.compare("\\'")==0) st2="\'";
 	else if(st2.compare("\a")==0) st2="\a";
 	else if(st2.compare("\f")==0) st2="\f";
 	else if(st2.compare("\r")==0) st2="\r";
 	else if(st2.compare("\b")==0) st2="\b";
 	else if(st2.compare("\v")==0) st2="\v";
 	else if(st2.compare("\0")==0) st2="\0";
 	return st2;
 }
 void AddkeyToken(string st){
 	ofstream file3;
	file3.open("1705081_token.txt",ios::app);
	file3<<"<"<<st<<">"<<' ';
	file3.close();
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<endl<<"Line no "<<line_count<<": Token "<<"<"<<st<<"> Lexeme ";
	transform(st.begin(), st.end(), st.begin(), ::tolower);
	file2<<st<<" found"<<endl;
	file2.close();
 	return;
 }
 void AddopToken(string st1,string st2){
 	ofstream file3;
	file3.open("1705081_token.txt",ios::app);
	file3<<"<"<<st1<<", "<<st2<<"> ";
	file3.close();
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<endl<<"Line no "<<line_count<<": Token "<<"<"<<st1<<"> Lexeme ";
	if(st1.compare("STRING")==0) file2<<strlex<<" found";
	else file2<<st2<<" found";
	if(st1.compare("STRING")==0){
		file2<<" --> <"<<st1<<", "<<st2<<"> ";
	}
	file2<<endl;
	file2.close();
 	return;
 }
 void AddotherToken(string st1,string st2){
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<endl<<"Line no "<<line_count<<": Token "<<"<"<<st1<<"> Lexeme ";
	file2<<st2<<" found";
	string tempyytext="";
	string temfinal=st2;
	if(st1.compare("CONST_CHAR")==0){
		tempyytext=st2.substr(1,st2.length()-2);
		temfinal=getConstChar(tempyytext);
		//cout<<temfinal<<endl;
	}
	if(st1.compare("CONST_CHAR")==0){
		//cout<<temfinal<<endl;
		file2<<" --><"<<st1<<", "<<temfinal<<"> ";
	}
	file2<<endl;
	file2.close();
	SymbolInfo *alreadyintab=stbl.Lookup(st2);
	if(alreadyintab==nullptr){
		SymbolInfo temp3(st2,st1);
    	stbl.Insert(temp3);
    	stbl.printAllscope();
    }
    ofstream file3;
	file3.open("1705081_token.txt",ios::app);
	file3<<"<"<<st1<<", "<<temfinal<<"> ";
	file3.close();
 	return;
 }
 

%}
DIGIT [0-9]
DIGITS {DIGIT}+
LETTER [a-zA-Z]
SPCHAR[\"nt\'afrbvo]
ALPHABET {LETTER}|_
ALPHANUMERIC {ALPHABET}|{DIGIT}

%%

([\r])?([\n]) { line_count++; }
[ \t\f\r\v]+ {}

"/*" {BEGIN MULCOMMENT;}
<MULCOMMENT>"*/" {BEGIN INITIAL;}
<MULCOMMENT>([\r])?([\n]) {line_count++;}
<MULCOMMENT>. {}
<MULCOMMENT><<EOF>> {
	counterror++;
	line_count--;
	stbl.printAllscope();
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<endl<<"Error at line no "<<line_count<<": Unterminated Comment /* unfinished ";
	file2<<yytext<<endl;
	file2<<endl;
	file2<<"Total lines: "<<line_count<<endl;
	file2<<"Total errors: "<<counterror<<endl;
	file2.close();
	return 0;
	}

"//" {BEGIN SINGLECOMMENT;}
<SINGLECOMMENT>(\\)([\r?\n]) {line_count++;}
<SINGLECOMMENT>([\r])?([\n]) {line_count++;BEGIN INITIAL;}
<SINGLECOMMENT>. {}

"\"" {strlex="\"";teyytext="\"";BEGIN STRINGSTATE;}
<STRINGSTATE>(\\)(([\r])?([\n])) {
							line_count++;
							}
<STRINGSTATE>(([\r])?([\n])) {
	line_count++;
	counterror++;
	fstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<endl<<"Error at line no "<<line_count<<": Unterminated String ";
	file2<<teyytext<<endl;
	file2.close();
	BEGIN INITIAL;
	}
<STRINGSTATE>(\\{SPCHAR}) {strlex=strlex+yytext;
							string temst=getConstChar(yytext);
							teyytext=teyytext+temst;}
<STRINGSTATE>"\"" {strlex=strlex+"\"";
		teyytext=teyytext+"\"";
		AddopToken("STRING",teyytext);
		BEGIN INITIAL;
		}
<STRINGSTATE>. {strlex=strlex+yytext;teyytext=teyytext+yytext;}

"if" { AddkeyToken("IF"); }
"for" { AddkeyToken("FOR"); }
"do" { AddkeyToken("DO"); }
"int" { AddkeyToken("INT"); }
"float" { AddkeyToken("FLOAT"); }
"void" { AddkeyToken("VOID"); }
"switch" { AddkeyToken("SWITCH"); }
"default" { AddkeyToken("DEFAULT"); }
"else" { AddkeyToken("ELSE"); }
"while" { AddkeyToken("WHILE"); }
"break" { AddkeyToken("BREAK"); }
"char" { AddkeyToken("CHAR"); }
"double" { AddkeyToken("DOUBLE"); }
"return" { AddkeyToken("RETURN"); }
"case" { AddkeyToken("CASE"); }
"continue" { AddkeyToken("CONTINUE"); }

{DIGITS} {AddotherToken("CONST_INT",yytext);}
({DIGITS})(\.{DIGITS})?((E|e)[+-]?{DIGITS})? {AddotherToken("CONST_FLOAT",yytext);}
({DIGITS})?(\.{DIGITS})(\.{DIGITS})+((E|e)[+-]?{DIGITS}(\.{DIGITS})*)? {
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<endl<<"Error at line no "<<line_count<<": Too many decimal points ";
	file2<<yytext<<endl;
	file2.close();
	counterror++; 
	}

({DIGITS})?(\.)?({DIGITS})?(((E|e)[+-]?{DIGITS}?)((\.{DIGITS}?)*))? {
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<endl<<"Error at line no "<<line_count<<": Ill formed number ";
	file2<<yytext<<endl;
	file2.close();
	counterror++;
	}

(\')((\\{SPCHAR})|({ALPHANUMERIC}))(\') {
			AddotherToken("CONST_CHAR",yytext);
			}

(\')(\') {
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<"Error at line no "<<line_count<<": Empty character constant error ";
	file2<<yytext<<endl;
	file2.close();
	counterror++;
	}
(\')({ALPHANUMERIC}){2,}(\') {
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<"Error at line no "<<line_count<<": Multi character constant error ";
	file2<<yytext<<endl;
	file2.close();
	counterror++;
	}
(\')[^\r\n\']* {
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<"Error at line no "<<line_count<<": Unterminated character ";
	file2<<yytext<<endl;
	file2.close();
	counterror++;
	}

"++" {AddopToken("INCOP",yytext);}
"--" {AddopToken("INCOP",yytext);}
"+" {AddopToken("ADDOP",yytext);}
"-" {AddopToken("ADDOP",yytext);}
"*" {AddopToken("MULOP",yytext);}
"/" {AddopToken("MULOP",yytext);}
"%" {AddopToken("MULOP",yytext);}
">=" {AddopToken("RELOP",yytext);}
"<=" {AddopToken("RELOP",yytext);}
"==" {AddopToken("RELOP",yytext);}
"!=" {AddopToken("RELOP",yytext);}
">" {AddopToken("RELOP",yytext);}
"<" {AddopToken("RELOP",yytext);}
"=" {AddopToken("ASSIGNOP",yytext);}
"&&" {AddopToken("LOGICOP",yytext);}
"||" {AddopToken("LOGICOP",yytext);}
"!" {AddopToken("NOT",yytext);}
"(" {AddopToken("LPAREN",yytext);}
")" {AddopToken("RPAREN",yytext);}
"{" {stbl.EnterScope();AddopToken("LCURL",yytext);}
"}" {AddopToken("RCURL",yytext);stbl.ExitScope();}
"[" {AddopToken("LTHIRD",yytext);}
"]" {AddopToken("RTHIRD",yytext);}
"," {AddopToken("COMMA",yytext);}
";" {AddopToken("SEMICOLON",yytext);}

({DIGITS})({ALPHANUMERIC})* {
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<endl<<"Error at line no "<<line_count<<": Invalid prefix on ID or invalid suffix on Number ";
	file2<<yytext<<endl;
	file2.close();
	counterror++;
	}
({ALPHABET})({ALPHANUMERIC})* {AddotherToken("ID",yytext);}

<<EOF>> {
	stbl.printAllscope();
	line_count--;
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<endl;
	file2<<"Total lines: "<<line_count<<endl;
	file2<<"Total errors: "<<counterror<<endl;
	file2.close();
	return 0;
	}
. {
	ofstream file2;
	file2.open("1705081_log.txt",ios::app);
	file2<<"Error at line no "<<line_count<<": Unrecognized character ";
	file2<<yytext<<endl;
	file2.close();
	counterror++;
	}

%%

int main(int argc,char *argv[]){
    stbl.EnterScope();
	string word;
    ofstream file2("1705081_log.txt");
   	file2.close();
   	ofstream file3("1705081_token.txt");
   	file3.close();
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	

	yyin= fin;
	yylineno=1;
	yylex();
	fclose(yyin);
	return 0;
}