%option noyywrap

%x vector
%x ternery


%{

#include<bits/stdc++.h>
#include "1805063_symbol_table.h"
#include <stack>

using namespace std;

int terc=0;
int c=0;
string vs="";
smbol_table * stbl=new smbol_table();

void keyword(string s1,string s2){
   ofstream f2;
	f2.open("token.txt",ios::app);
    f2<<"<"<<s1<<"> "<<s2<<endl;
	f2<<endl;
    
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

%%

"<" {
    vs="";
    BEGIN vector;
    c=1;
    
}

<vector>("<") {
    c++;
   if(vs.compare("")!=0){
     if ( stbl->insert(vs,"vector")){
        stbl->printall();
    }
   }
   
    vs="";

}
<vector>(">") {
    c--;

    if(vs.compare("")!=0){
         if ( stbl->insert(vs,"vector")){
        stbl->printall();
        }
    }
   
    
    
    
    
    
    vs="";
    
}

<vector>({alphabet}[ ]{alphabet}) {
    ofstream f2;
    f2.open("token.txt",ios::app);
    f2<<"<"<<"error space"<<">"<<endl;
    f2.close();
   

}
<vector>{alphabet} {
   vs=vs+yytext;

}
<vector>(([\r])?([\n])) {
    if(c!=0){
        
       
    ofstream f2;
    f2.open("token.txt",ios::app);
    f2<<"<"<<"error for not close"<<">"<<yytext<<endl;
    f2.close();
        

        
        

    }
    
    BEGIN INITIAL;
}
<vector><<EOF>> {
    ofstream f2;
    f2.open("token.txt",ios::app);
    f2<<"<"<<"error for eof"<<">"<<yytext<<endl;
    f2.close();
    BEGIN INITIAL;
}



"int" { keyword("INT",yytext);}
"(" {ofstream f2;
    f2.open("token.txt",ios::app);
    f2<<"<"<<"LPAREN"<<">"<<yytext<<endl;
    f2.close();
    }

({digits}) {
    keyword("integer",yytext);
}
({digits})?(\.{digits})((E|e)[+-]?{digits})? {
    keyword("CONST_FLOAT",yytext);
}


({alphanum})(">="|"<="|"=="|"!="|">"|"<"|"&&"|"||")({alphanum})("?") {
    terc=1;
    BEGIN ternery;
}
<ternery>({alphanum})(":")({alphanum})(">="|"<="|"=="|"!="|">"|"<"|"&&"|"||")({alphanum})("?") {
    terc++;
    terc--;
}
<ternery>({alphanum})(":")({alphanum}) {
    terc--;
}


<ternery>(";") {
    if(terc!=0){
        ofstream f2;
        f2.open("token.txt",ios::app);
        f2<<"<"<<"error "<<">"<<endl;
        f2.close();
        

    }
    else{
        ofstream f2;
        f2.open("token.txt",ios::app);
        f2<<"<"<<"ternery found"<<">"<<endl;
        f2.close();
    }
    BEGIN INITIAL;
} 


(([\r])?([\n])) {

}

. {}

%%
int main(int argc,char *argv[]){
    stbl->enterscope("1",7);
	

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
    stbl->~smbol_table();
	return 0;
}