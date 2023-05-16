
%option noyywrap
%x SINGLECOMMENT
%x MULTICOMMENT
%x STRINGSTATE

%{
#include<bits/stdc++.h>
#include "1805063_symbol_table.h"
using namespace std;

int line_count=1;
int errors=0;
int stringcount=0;
int comcount=0;
int mcomncount=0;


string stf2="";
string tyy="";
string comnstring="";
string mcomnstring="";
smbol_table * stbl=new smbol_table();

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
void addkeywords(string s,string s2){
    ofstream f3;
    f3.open("1805063_token.txt",ios::app);
    f3<<"<"<<s<<">"<<" ";
    f3.close();
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"Line no: "<<line_count<<" "<<"Token <"<<s<<"> Lexeme "<<s2 <<" found"<<endl;
    f2.close();
    return;

}
void addoptoken(string s1,string s2){
     ofstream f3;
    f3.open("1805063_token.txt",ios::app);
    f3<<"<"<<s1<<","<<s2<<"> ";
    f3.close();
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"Line no: "<<line_count<<" "<<"Token <"<<s1<<"> Lexeme "<<s2 <<" found"<<endl;
    f2.close();
    return;
}
void addidtokens(string s1,string s2){
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"Line no : "<< line_count<<" Token <"<<s1<<"> Lexeme "<< s2<<" found"<<endl;
    f2.close();
    bool r=stbl->insert(s2,s1);
    if(r){
        stbl->printall();

    }
    ofstream f3;
    f3.open("1805063_token.txt",ios::app);
    f3<<"<"<<s1<<","<< s2<<">";
    f3.close();
    return;

}
void addconsttoken(string s1,string s2){
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"Line no : "<< line_count<<"Token <"<<s1<<"> Lexeme"<< s2<<" found"<<endl;

    if(s1.compare("CONST_INT")==0){
        f2.close();
         bool r=stbl->insert(s2,s1);
        if(r){
            stbl->printall();

        }

    }
    else if(s1.compare("CONST_FLOAT")==0){
        f2.close();
         bool r=stbl->insert(s2,s1);
        if(r){
            stbl->printall();

        }

    }
    else if(s1.compare("ID")==0){
        f2.close();
         bool r=stbl->insert(s2,s1);
        if(r){
            stbl->printall();

        }

    }
    else if(s1.compare("CONST_CHAR")==0){
        
        string t1="";
        string t2="";
        t1=s2.substr(1,s2.length()-2);
        t2=getConstChar(t1);
        f2<<" --><"<<s1<<", "<<t2<<"> "<<endl;

        f2.close();
        bool r=stbl->insert(s2,s1);
        if(r){
            stbl->printall();

        }
         ofstream f3;
        f3.open("1805063_token.txt",ios::app);
        f3<<"<"<<s1<<","<< t2<<">";
        f3.close();
        return;

    }
    ofstream f3;
    f3.open("1805063_token.txt",ios::app);
    f3<<"<"<<s1<<","<< s2<<">";
    f3.close();
    return;

}
void errorreport(string s1,string s2){
    ofstream f2;
    
    f2.open("1805063_log.txt",ios::app);
    f2<<"Error at line no: "<<line_count-stringcount<<"Error : "<<s1<<"  "<<s2<<endl;
    f2.close();
    errors++;

}
void addstringtoken(string s1){
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"Line no : "<< line_count-stringcount<<" Token <"<<s1<<"> Lexeme "<< stf2<<" found";
    f2<<" --><"<<s1<<", "<<tyy<<"> "<<endl;

    f2.close();

    ofstream f3;
    f3.open("1805063_token.txt",ios::app);
    f3<<"<"<<s1<<","<< tyy<<">";
    f3.close();
    return;

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
([\r]?)([\n]) {line_count++;}
{whitespace} {}


("/*") {
    mcomncount=0;
    //cout<<"has";
    mcomnstring="/*";
    BEGIN MULTICOMMENT;
}

<MULTICOMMENT>([\r])?([\n]) {
    line_count++;
    //cout<<"inqweweq";
    mcomncount++;
    mcomnstring=mcomnstring+yytext;
}

<MULTICOMMENT>("*/") {
    
    mcomnstring=mcomnstring+"*/";
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"Line no : "<< line_count-mcomncount<<" Token <"<<"COMMENT"<<"> Lexeme "<< mcomnstring<<" found"<<endl;
    
   // line_count++;
    f2.close();
    mcomncount=0;
    BEGIN INITIAL;

}
<MULTICOMMENT>. {
    mcomnstring=mcomnstring+yytext;
}


<MULTICOMMENT><<EOF>> {

    errors++;
    //line_count++;
   

   
	
	ofstream f2;
	f2.open("1805063_log.txt",ios::app);
    f2<<"Error at line no: "<<line_count-mcomncount<<"Error : Unterminated Comment "<<mcomnstring<<endl;
	f2<<endl;
    
    f2.close();
    stbl->printall();
    f2.open("1805063_log.txt",ios::app);
	f2<<"Total lines: "<<line_count<<endl;
	f2<<"Total errors: "<<errors<<endl;
	f2.close();
	return 0;

}




("//") {
    comcount=0;
    comnstring="//";
    BEGIN SINGLECOMMENT;

}
<SINGLECOMMENT>(\\)([\r?\n]) {
    line_count++;
    comcount++;
    cout<<"in";
    comnstring=comnstring+yytext;
}
<SINGLECOMMENT>(([\r])?([\n])) {
   
    
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"Line no : "<< line_count-comcount<<" Token <"<<"COMMENT"<<"> Lexeme "<< comnstring<<" found"<<endl;
    

    f2.close();
    line_count++;
    comcount=0;
    
    BEGIN INITIAL;

}
<SINGLECOMMENT>. {
    comnstring=comnstring+yytext;
}



("\"") {
    stringcount=0;
    stf2="\"";
    tyy="\"";
    BEGIN STRINGSTATE;
}
<STRINGSTATE>(\\)(([\r])?([\n])) {
    stringcount++;
    line_count++;
    stf2=stf2+yytext;
}
<STRINGSTATE>(([\r])?([\n])) {
    string s=" Unterminated string ";
    
    errorreport(s,stf2);
    line_count++;
    stringcount=0;
    BEGIN INITIAL;
}
<STRINGSTATE>(\\)({s_char}) {
    stf2=stf2+yytext;
    string t=getConstChar(yytext);
    tyy=tyy+t;
}
<STRINGSTATE>("\"") {
    stf2=stf2+"\"";
    tyy=tyy+"\"";
    addstringtoken("STRING");
    stringcount=0;

    BEGIN INITIAL;
}
<STRINGSTATE>. {
    stf2=stf2+yytext;
    tyy=tyy+yytext;
}







"if" {addkeywords("IF",yytext);}
"for" {addkeywords("FOR",yytext);}

"do" { addkeywords("DO",yytext); }
"int" { addkeywords("INT",yytext); }
"float" { addkeywords("FLOAT",yytext); }
"void" { addkeywords("VOID",yytext); }
"switch" { addkeywords("SWITCH",yytext); }
"default" { addkeywords("DEFAULT",yytext); }
"else" { addkeywords("ELSE",yytext); }
"while" {addkeywords("WHILE",yytext); }
"break" { addkeywords("BREAK",yytext); }
"char" { addkeywords("CHAR",yytext); }
"double" { addkeywords("DOUBLE",yytext); }
"return" { addkeywords("RETURN",yytext); }
"case" { addkeywords("CASE",yytext); }
"continue" { addkeywords("CONTINUE",yytext); }


{digits} {addconsttoken("CONST_INT",yytext);}
({digits})?(\.{digits})?((E|e)[+-]?{digits})? {addconsttoken("CONST_FLOAT",yytext);}

({digits})?(\.{digits})+(\.{digits})+((E|e)[+-]?{digits}\.({digits})*)? {
    errorreport(" Too many decimal points ",yytext);
    
}
({digits})?(\.)?({digits})?((E|e)[+-]?({digits})?(\.{digits})+) {
    errorreport(" Ill formed number ",yytext);
}

(\')(\') {
    errorreport(" Empty character constant error ",yytext);
}
(\')({alphanum}){2,}(([ ])({alphanum})*)?(\') {
    errorreport(" Multi character constant error ",yytext);
}

(\')(\\{s_char})?[^\r\n\']* {
    errorreport(" Unfinished character constant ",yytext);
}



"++" {addoptoken("INCOP",yytext);}
"--" {addoptoken("INCOP",yytext);}
"+" {addoptoken("ADDOP",yytext);}
"-" {addoptoken("ADDOP",yytext);}

"*"|"/"|"%" {addoptoken("MULOP",yytext);}


">="|"<="|"=="|"!="|">"|"<" {addoptoken("RELOP",yytext);}

"=" {addoptoken("ASSIGNOP",yytext);}
"&&"|"||" {addoptoken("LOGICOP",yytext);}

"!" {addoptoken("NOT",yytext);}
"(" {addoptoken("LPAREN",yytext);}
")" {addoptoken("RPAREN",yytext);}
"{" {stbl->enterscope("d",7);addoptoken("LCURL",yytext);}
"}" {addoptoken("RCURL",yytext);stbl->exitscope();}
"[" {addoptoken("LTHIRD",yytext);}
"]" {addoptoken("RTHIRD",yytext);}
"," {addoptoken("COMMA",yytext);}
";" {addoptoken("SEMICOLON",yytext);}
"&"|"|"|"^"|"<<"|">>" {addoptoken("BITWISE",yytext);}

(\')((\\{s_char})|({alphanum}))(\') { addconsttoken("CONST_CHAR",yytext);}

({digits})({alphanum})* {
    errorreport(" : Invalid prefix on ID or invalid suffix on Number ",yytext);
}
({alphabet})({alphanum}*) {
    addidtokens("ID",yytext);
    
    }

<<EOF>> {

	stbl->printall();
	ofstream f2;
	f2.open("1805063_log.txt",ios::app);
	f2<<endl;
	f2<<"Total lines: "<<line_count<<endl;
	f2<<"Total errors: "<<errors<<endl;
	f2.close();
	return 0;
	}


. {
   errorreport("Unrecognized character"," ");
}
%%
int main(int argc,char *argv[]){
    stbl->enterscope("1",7);
	string word;
    ofstream file2("1805063_log.txt");
   	file2.close();
   	ofstream file3("1805063_token.txt");
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
    stbl->~smbol_table();
	return 0;
}