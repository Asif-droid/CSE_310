%{
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
#include "1805063_symbol_table.h"


using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
int line_count = 1;
int lastsemicolon;
int error = 0;

smbol_table *table=new smbol_table();
string type;



void line_log(int a){
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"line no: "<<a<<endl;
    
    f2.close();

}
void line_error(int a){
    ofstream f3;
    f3.open("1805063_error.txt",ios::app);
    f3<<"line no: "<<a<<endl;
    
    f3.close();

}
void logout(string s){
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<s;
    
    f2.close();

}
void logout(string s,int a){
    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"line_no: "<<a<<" "<<s<<endl;
    
    f2.close();
}
void errorout(string s){
    ofstream f2;
    f2.open("1805063_error.txt",ios::app);
    f2<<s<<endl;
    
    f2.close();

}
void errorout(string s,int a){
    ofstream f2;
    f2.open("1805063_error.txt",ios::app);
    f2<<"line_no: "<<a<<" "<<s<<endl;
    
    f2.close();

}
void yyerror(char *s)
{
	
}


%}



%union {
     smbol_info *symbol;
     vector<smbol_info*>* vectorsymbol;
}


%token<symbol> IF ELSE FOR WHILE DO INT CHAR FLOAT VOID RETURN CONTINUE  NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD PRINTLN
%token<symbol>  COMMA SEMICOLON ADDOP MULOP INCOP DECOP LOGICOP RELOP ASSIGNOP UNRECOGNISED_OP
%token<symbol> ID CONST_INT CONST_FLOAT


%type<symbol> type_specifier
%type<vectorsymbol> declaration_list var_declaration func_declaration parameter_list unit factor unary_expression term simple_expression rel_expression logic_expression expression variable expression_statement arguments argument_list statement statements compound_statement func_definition program 

%left RELOP LOGICOP
%left ADDOP
%left MULOP

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE






%%

start : program
	{

         $$ = new vector<smbol_info*>;
		//write your code in this block in all the similar blocks below

       logout("start programme",line_count-1);
	}
	;

program : program unit {
        
        logout(" program : program unit",line_count);
        $$ = new vector<smbol_info*>;
		for(int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
            logout( $1->at(i)->getname());
			
			if($1->at(i)->getname() == "int" || $1->at(i)->getname() == "float" || $1->at(i)->getname() == "void" || $1->at(i)->getname() == "return")
				logout(" ");
			if($1->at(i)->getname() == ";" || $1->at(i)->getname() == "{" || $1->at(i)->getname() == "}")
				logout("\n");
		}
		for(int i = 0; i < $2->size(); i++){
            $$->push_back($2->at(i));
            logout( $2->at(i)->getname());

			if($2->at(i)->getname() == "int" || $2->at(i)->getname() == "float" || $2->at(i)->getname() == "void" || $2->at(i)->getname() == "return")
				logout(" ");

			if($2->at(i)->getname() == ";" || $2->at(i)->getname() == "{" || $2->at(i)->getname() == "}")
				logout("\n");
		}
		logout("\n\n");

    }
	| unit {
       
        logout(" program : unit \n",line_count);
        $$ = new vector<smbol_info*>();
		for(int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
            logout($1->at(i)->getname());
            
			
			if($1->at(i)->getname() == "int" || $1->at(i)->getname() == "float" || $1->at(i)->getname() == "void" || $1->at(i)->getname() == "return")
    			logout(" ");
			if($1->at(i)->getname() == ";" || $1->at(i)->getname() == "{" || $1->at(i)->getname() == "}")
				logout("\n");
		}
		logout("\n\n");
    }
	;
	
unit : var_declaration {
        
        logout(" unit : var_declaration\n",line_count);
        $$ = new vector<smbol_info*>();
        for(int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
            logout($1->at(i)->getname());
            
            if($1->at(i)->getname() == "int" || $1->at(i)->getname() == "float" || $1->at(i)->getname() == "void")
                logout(" ");
        }
        logout("\n\n");
    }
    | func_declaration {
        
     	logout(" unit : func_declaration\n",line_count);
        $$ = new vector<smbol_info*>();
     		for(int i = 0; i < $1->size(); i++){
                $$->push_back($1->at(i));
				logout($1->at(i)->getname());
				
				if($1->at(i)->getname() == "int" || $1->at(i)->getname() == "float" || $1->at(i)->getname() == "void")
					logout(" ");
			}
		logout("\n\n"); 
    }
    | func_definition {
        
            logout(" unit : func_definition\n",line_count);
            $$ = new vector<smbol_info*>();
     		for(int i = 0; i < $1->size(); i++){
				logout($1->at(i)->getname());
				$$->push_back($1->at(i));
				if($1->at(i)->getname() == "int" || $1->at(i)->getname() == "float" || $1->at(i)->getname() == "void" || $1->at(i)->getname() == "return")
					logout (" ");
				if($1->at(i)->getname() == ";" || $1->at(i)->getname() == "{" || $1->at(i)->getname() == "}")
					logout("\n");
			}
		logout("\n\n"); 
    }
    ;




func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
        
        logout("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);
        lastsemicolon=line_count;
        $$ = new vector<smbol_info*>();
        // semantic error----------//
        if(table->lookup($2->getname()) != NULL){   // Multiple declaration of function
           
            
            logout("Error: Multiple declaration of "+ $2->getname(),line_count );
            
            errorout("Multiple declaration of "+ $2->getname(),line_count );
            error++;
        }
        vector<string> param_name;       // Multiple declaration of parameter
        for(int i = 0; i < $4->size(); i++){  
            if($4->at(i)->gettype() == "ID"){
                param_name.push_back($4->at(i)->getname());
                for(int j = 0; j < param_name.size()-1; j++){
                    if($4->at(i)->getname() == param_name.at(j)){
                        param_name.pop_back();
                       
                        logout("Error: Multiple declaration of "+ $4->at(i)->getname()+" in parameter\n",line_count);
                        
                        errorout(" Multiple declaration of "+ $4->at(i)->getname() +" in parameter\n",line_count);
                        error++;
                    }
                }
            }
        }
        //Insert func declaration Into Table------------------//
        bool inserted =table->insert($2->getname(),"ID",$1->gettype(), "func");
        //---------------//
        // store parameter type sequentially
        if(inserted){   
            smbol_info* temp = table->lookup($2->getname());
            for(int i = 0; i < $4->size(); i++){
                if($4->at(i)->gettype() == "INT" || $4->at(i)->gettype() == "FLOAT" || $4->at(i)->gettype() == "VOID")
                    temp->set_param_type($4->at(i)->gettype());
            }
        }
        //----------//
       
        logout( $1->getname());
        logout( $2->getname());
        logout( $3->getname());
        $$->push_back($1);
        $$->push_back($2);
        $$->push_back($3);
        for(int i = 0; i < $4->size(); i++){
            logout( $4->at(i)->getname());
        
            $$->push_back($4->at(i));
            if($4->at(i)->getname() == "int" || $4->at(i)->getname() == "float" || $4->at(i)->getname() == "void")
                logout(" ");
        }
        
        logout($5->getname());
        logout($6->getname()+"\n\n");
       
        $$->push_back($5);
        $$->push_back($6);

    }
    | type_specifier ID LPAREN RPAREN SEMICOLON {
        $$ = new vector<smbol_info*>();
        logout("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
        lastsemicolon=line_count;

        // semantic error----------//
        if(table->lookup($2->getname()) != NULL){   // Multiple declaration of function
            
            logout("Error: Multiple declaration of "+$2->getname()+"\n ",line_count);
            
            errorout("Error: Multiple declaration of "+$2->getname()+"\n ",line_count);
            error++;
        }
        //----------//
        
        logout( $1->getname()+" ");
        logout( $2->getname()+" ");
        logout( $3->getname()+" ");
        logout( $4->getname()+" ");
        logout( $5->getname()+"\n\n");
        
        $$->push_back($1);
        $$->push_back($2);
        $$->push_back($3);
        $$->push_back($4);
        $$->push_back($5);
        //Insert func declaration Into Table------------------//
        bool inserted = table->insert($2->getname(),"ID",$1->gettype(), "func");
        //---------------//
    }
    ;
func_definition : type_specifier ID LPAREN parameter_list RPAREN {
        if(table->lookup($2->getname()) == NULL)
            bool inserted = table->insert($2->getname(),"ID",$1->gettype(), "func");
            
        //semantic error-----------//
        else if((table->lookup($2->getname()))->getwhichvar() != "func"){
            
            logout("Error:  Multiple declaration of "+ $2->getname() + "\n",line_count);
            
            
            errorout("Error:  Multiple declaration of "+ $2->getname() + "\n",line_count);
            error++;
        }
        else if((table->lookup($2->getname()))->getdefined()){     // Function Already Defined
           logout("Error:  Multiple declaration of "+ $2->getname() + "\n",line_count);
            
            
            errorout("Error:  Multiple declaration of "+ $2->getname() + "\n",line_count);
            error++;
        }
        else if(!(table->lookup( $2->getname()))->getdefined()){        // Return type doesn't match with declaration
            (table->lookup( $2->getname()))->setdefined();
            if((table->lookup($2->getname()))->get_var_type() != $1->gettype()){
                
                logout("Error: Return type mismatch with function declaration in function "+ $2->getname()+"\n",line_count);
                errorout("Error: Return type mismatch with function declaration in function "+ $2->getname()+"\n",line_count);
                error++;
            }
        }
        smbol_info* temp = table->lookup( $2->getname());
        temp->setdefined();
        
        
        vector<string> param_name;       // Multiple declaration of parameter
        for(int i = 0; i < $4->size(); i++){  
            if($4->at(i)->gettype() == "ID"){
                param_name.push_back($4->at(i)->getname());
                for(int j = 0; j < param_name.size()-1; j++){
                    if($4->at(i)->getname() == param_name.at(j)){
                        param_name.pop_back();
                        
                        logout("Error: Multiple declaration of "+$4->at(i)->getname()+" in parameter\n",line_count);
                        
                       
                        errorout("Error: Multiple declaration of "+$4->at(i)->getname()+" in parameter\n",line_count);
                        error++;
                    }
                }
            }
        }
        //------------//
        table->enterscope("x",7);
        
        for (int i = 0; i < $4->size(); i++){      // Insert parameter into table
            if($4->at(i)->gettype() == "ID"){
                if($4->at(i-1)->gettype() == "INT")
                    bool inserted = table->insert( $4->at(i)->getname(),"ID", "INT","var");
                else if($4->at(i-1)->gettype() == "FLOAT")
                    bool inserted = table->insert( $4->at(i)->getname(),"ID", "FLOAT", "var");
                else if($4->at(i-1)->gettype() == "VOID")
                    bool inserted = table->insert( $4->at(i)->getname(),"ID", "VOID", "var");
            }
        }
            
            if(temp->getparamsize() == 0){       // store parameter type sequentially
                for(int i = 0; i < $4->size(); i++){
                if($4->at(i)->gettype() == "INT" || $4->at(i)->gettype() == "FLOAT" || $4->at(i)->gettype() == "VOID")
                    temp->set_param_type($4->at(i)->gettype());
                }
            }
            else{          // function argument check with declaration
                vector<string> parameter_type;
                for(int i = 0; i < $4->size(); i++){
                    if($4->at(i)->gettype() == "INT" || $4->at(i)->gettype() == "FLOAT" || $4->at(i)->gettype() == "VOID"){
                        parameter_type.push_back($4->at(i)->gettype());
                    }
                }
                if(parameter_type.size() != temp->getparamsize()){
                    
                    logout("Error:Total number of arguments mismatch with declaration in function "+ $2->getname() + "\n",line_count);
                    
                    errorout("Error:Total number of arguments mismatch with declaration in function "+ $2->getname() + "\n",line_count);
                    error++;
                } 
                else{
                    for(int i = 0; i < temp->getparamsize(); i++){
                        if(parameter_type.at(i) != temp->get_param_at(i)){
                            
                            string s=to_string(i+1);
                            logout("Error: "+s+ "th argument mismatch in function "+ $2->getname() +"\n");
                            errorout("Error: "+s+ "th argument mismatch in function "+ $2->getname() +"\n");
                            error++;
                        }
                    }
                }
            }
    } compound_statement { 
        table->printall();
        cout<<"printall"<<endl;
        table->exitscope();
    }
    {
        $$ = new vector<smbol_info*>();
        
       
        logout("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);
        
        logout( $1->getname()+" ");
        logout( $2->getname()+" ");
        logout( $3->getname()+" ");
        $$->push_back($1);
        $$->push_back($2);
        $$->push_back($3);
        for (int i = 0; i < $4->size(); i++){
            
            logout($4->at(i)->getname()+" ");
            $$->push_back($4->at(i));
            if($4->at(i)->getname() == "int" || $4->at(i)->getname() == "float" || $4->at(i)->getname() == "void")
                logout ( " ");
        }
        logout ($5->getname()+" ");
        $$->push_back($5);
        for (int i = 0; i < $7->size(); i++){
            logout ($7->at(i)->getname()+" ");
            $$->push_back($7->at(i));
            if($7->at(i)->getname() == "int" || $7->at(i)->getname() == "float" || $7->at(i)->getname() == "void" || $7->at(i)->getname() == "return")
                logout ( " ");
            if($7->at(i)->getname() == ";" || $7->at(i)->getname() == "{" || $7->at(i)->getname() == "}")
                logout ("\n");
        }
        logout ( "\n\n");

    }

    | type_specifier ID LPAREN RPAREN {
        if(table->lookup( $2->getname()) == NULL)
            bool inserted = table->insert( $2->getname(),"ID", $1->gettype(), "func");
            
            //semantic error-----------//
        else{        // Return type doesn't match with declaration
            smbol_info* temp = table->lookup( $2->getname());
            if(temp->get_var_type() != $1->gettype()){
                
                logout("Error: Return type mismatch with function declaration in function " + $2->getname() + "\n",line_count);
                errorout("Error: Return type mismatch with function declaration in function " + $2->getname() + "\n",line_count);
                error++;
            }
        }
        smbol_info* temp = table->lookup($2->getname());  // Function Already Defined
        if(temp->getdefined()){
            
            logout("Error: Multiple Definition of " + $2->getname()+"\n ",line_count);
            errorout("Error: Multiple Definition of " + $2->getname()+"\n ",line_count);
            error++;
        }
        else
            temp->setdefined();
        
            
        //------------//
        table->enterscope("x",7);
    }
    compound_statement {
        table->printall();
        cout<<"printall"<<endl;
        table->exitscope();
    }
    {
        $$ = new vector<smbol_info*>();
        
        
        logout("func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);
        logout ($1->getname()+" "+ $2->getname()+ $3->getname()+$4->getname());
        $$->push_back($1);
        $$->push_back($2);
        $$->push_back($3);
        $$->push_back($4);
        for (int i = 0; i < $6->size(); i++){
            logout ($6->at(i)->getname());
            $$->push_back($6->at(i));
            if($6->at(i)->getname() == "int" || $6->at(i)->getname() == "float" || $6->at(i)->getname() == "void" || $6->at(i)->getname() == "return")
                logout (" ");
            if($6->at(i)->getname() == ";" || $6->at(i)->getname() == "{" || $6->at(i)->getname() == "}")
                logout ("\n");
        }
        logout ("\n\n");
    }
    ;	

parameter_list  : parameter_list COMMA type_specifier ID {
        $$ = new vector<smbol_info*>();
        logout("parameter_list : parameter_list COMMA type_specifier ID\n",line_count);
       
        for(int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
            if($1->at(i)->getname() == "int" || $1->at(i)->getname() == "float" || $1->at(i)->getname() == "void")
                logout ( " ");
        }
        logout ( $2->getname()+" "+ $3->getname()+ " " +$4->getname() + "\n\n"); 
        $$->push_back($2);
        $$->push_back($3);
        $$->push_back($4);
    }
    | parameter_list COMMA type_specifier{
        $$ = new vector<smbol_info*>();
        logout("parameter_list : parameter_list COMMA type_specifier\n",line_count);
        
        for(int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        logout ( $2->getname()+" " +$3->getname() + "\n\n");
        $$->push_back($2);
        $$->push_back($3);
    }
    | type_specifier ID{
        $$ = new vector<smbol_info*>();
        logout("parameter_list : type_specifier ID\n",line_count);
        logout ( $1->getname()+" " +$2->getname() + "\n\n");
       
        $$->push_back($1);
        $$->push_back($2);
    }
    | type_specifier{
        $$ = new vector<smbol_info*>();
        logout("parameter_list : type_specifier\n",line_count);
        logout ($1->getname()+ "\n\n");
       
        $$->push_back($1);
    }
    | type_specifier error {
        $$ = new vector<smbol_info*>();
        logout("Syntax error\n",line_count);
        logout ($1->getname()+ "\n\n");
        errorout("Syntax error\n",line_count);
        error++;
        $$->push_back($1);
        yyclearin;
    }
    | parameter_list COMMA type_specifier error {
        $$ = new vector<smbol_info*>();
        logout("Syntax error\n",line_count);
        
        for(int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        errorout("Syntax error\n",line_count);
        error++;
        yyclearin;

    }
    ;

compound_statement : LCURL statements RCURL{
        
		 	
        logout("compound_statement : LCURL statements RCURL\n",line_count);
        logout ($1->getname() + "\n");
        $$ = new vector<smbol_info*>();
		 	$$->push_back($1);
		  	for(int i = 0; i < $2->size(); i++){
		  		$$->push_back($2->at(i));
		  		logout ($2->at(i)->getname());
				if($2->at(i)->getname() == "int" || $2->at(i)->getname() == "float" || $2->at(i)->getname() == "void" || $2->at(i)->getname() == "return")
					logout ( " ");
				if($2->at(i)->getname() == ";" || $2->at(i)->getname() == "{" || $2->at(i)->getname() == "}")
					logout ( "\n");
		  	}
			logout ($3->getname() +"\n\n");
			$$->push_back($3);
    }
    | LCURL RCURL{
        $$ = new vector<smbol_info*>();
       
        logout("compound_statement : LCURL RCURL\n",line_count);
        logout ( $1->getname()+" " +$2->getname()+ "\n\n");
        $$->push_back($1);
        $$->push_back($2);
    }
    ;

var_declaration : type_specifier declaration_list SEMICOLON{
        $$ = new vector<smbol_info*>();
        lastsemicolon=line_count;
			logout("var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);
			// semantic error-----------//
			if($1->gettype() == "VOID"){
				
                logout("Error: Variable type cannot be void\n",line_count);
				
                errorout("Error: Variable type cannot be void\n",line_count);
				error++;
			}
			//---------------//
		 	logout ( $1->getname() + " ");
		 	$$->push_back($1);
		  	for(int i = 0; i < $2->size(); i++){
		  		$$->push_back($2->at(i));
		  		logout ( $2->at(i)->getname());
		  	}
			
			logout ($3->getname() + "\n\n");
			$$->push_back($3);
    }
    ;

type_specifier	: INT{
       
        logout("type_specifier :  INT\n",line_count);
        logout ($1->getname() + "\n\n");
        $$ = $1;
        type = "INT";
    }
    | FLOAT {
        
        logout("type_specifier :  FLOAT\n",line_count);
        logout ($1->getname() +"\n\n");
        $$ = $1;
        type = "FLOAT";
    }
    | VOID {
        
        logout("type_specifier :  VOID\n",line_count);
        logout ($1->getname() + "\n\n");
        $$ = $1;
        type = "VOID";
    }
    ;



 		 
declaration_list : declaration_list COMMA ID{
        $$ = new vector<smbol_info*>();
        //semantic error------//
        bool inserted=false;
        if(type != "VOID"){
                inserted = table->insert( $3->getname(),"ID",type,"var");
        }
        
            
        if ( inserted != true){
            
            logout("Error: Multiple declaration of " + $3->getname() + "\n",line_count);
            errorout("Error: Multiple declaration of " + $3->getname() + "\n",line_count);
            error++;
        }
        //--------//
        
        
        logout(" declaration_list : declaration_list COMMA ID\n",line_count);
        for(int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
            logout ($1->at(i)->getname());
        }
        logout ( $2->getname()+" "+ $3->getname()+ "\n\n");
        $$->push_back($2);
        $$->push_back($3);
    }
    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
        $$ = new vector<smbol_info*>();
        //semantic error------//
			bool inserted=false;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = table->insert( $3->getname(),"ID",type,"array");
			if(inserted != true){
				logout("Error: Multiple declaration of " + $3->getname() + "\n",line_count);
                errorout("Error: Multiple declaration of " + $3->getname() + "\n",line_count);
                error++;
			}
			//--------//
		  	
		  	
		  	logout("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);
            for(int i = 0; i < $1->size(); i++){
		  		$$->push_back($1->at(i));
		  		logout ($1->at(i)->getname());
		  	}
			logout($2->getname()+" "+ $3->getname() +" "+  $4->getname()+" "+ $5->getname()+" "+$6->getname()+ "\n\n");
			$$->push_back($2);
			$$->push_back($3);
			$$->push_back($4);
			$$->push_back($5);
			$$->push_back($6);
    }
    | ID {
        cout<<"id from y hsjdahdjasdhjshdbajbd"<<endl;
        //semantic error------//
        bool inserted=false;
        if(type != "VOID")     // don't insert void variable in symboltable
            inserted = table->insert( $1->getname(),"ID",type, "var");
        if(inserted != true){
            logout("Error: Multiple declaration of " + $1->getname() + "\n",line_count);
            errorout("Error: Multiple declaration of " + $1->getname() + "\n",line_count);
            error++;
        }
        //--------//
        $$ = new vector<smbol_info*>();
        
        logout(" declaration_list : ID\n",line_count);
        logout ( $1->getname() + "\n\n");
        $$->push_back($1);
    }
    | ID LTHIRD CONST_INT RTHIRD{
        $$ = new vector<smbol_info*>();
        //semantic error------//
        bool inserted =false;
        if(type != "VOID")      // don't insert void variable in symboltable
            inserted = table->insert( $1->getname(),"ID",type, "array");
        if(inserted != true){
            logout("Error: Multiple declaration of " + $1->getname() + "\n",line_count);
            errorout("Error: Multiple declaration of " + $1->getname() + "\n",line_count);
            error++;
        }
        //--------//
        
       
        logout("declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
        logout ( $1->getname() +" "+ $2->getname() +" "+ $3->getname()+" "+ $4->getname() + "\n\n");
        $$->push_back($1);
        $$->push_back($2);
        $$->push_back($3);
        $$->push_back($4);
    }
    | declaration_list var_declaration_invalid_delimiters ID {
        cout<<"here"<<endl;
        $$ = new vector<smbol_info*>();
        for(int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
            logout ($1->at(i)->getname());
		}
        logout("Syntax error",line_count);
        errorout("Syntax error",line_count);
        error++;
    }
    | declaration_list var_declaration_invalid_delimiters ID LTHIRD CONST_INT RTHIRD {
        $$ = new vector<smbol_info*>();
        for(int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
            logout ($1->at(i)->getname());
		}
        logout("Syntax error",line_count);
        errorout("Syntax error",line_count);
        error++;
    }
    ;

var_declaration_invalid_delimiters : ADDOP | MULOP | LOGICOP | INCOP | DECOP | RELOP | ASSIGNOP | NOT
	;
 		
statements : statement{
        $$ = new vector<smbol_info*>();
	  	
        logout("statements : statement\n",line_count);
		for(int i = 0; i < $1->size(); i++){
			logout ($1->at(i)->getname());
			$$->push_back($1->at(i));
			if($1->at(i)->getname() == "int" || $1->at(i)->getname() == "float" || $1->at(i)->getname() == "void" || $1->at(i)->getname() == "return")
				logout (" ");
			if($1->at(i)->getname() == ";" || $1->at(i)->getname() == "{" || $1->at(i)->getname() == "}")
					logout ("\n");
		}
		logout ("\n\n");
    

    }
    | statements statement{
        $$ = new vector<smbol_info*>();
	  	
        logout("statements : statements statement\n",line_count);
		for(int i = 0; i < $1->size(); i++){
			logout ($1->at(i)->getname());
			$$->push_back($1->at(i));
			if($1->at(i)->getname() == "int" || $1->at(i)->getname() == "float" || $1->at(i)->getname() == "void" || $1->at(i)->getname() == "return")
				logout (" ");
			if($1->at(i)->getname() == ";" || $1->at(i)->getname() == "{" || $1->at(i)->getname() == "}")
					logout ("\n");
		}
		for(int i = 0; i < $2->size(); i++){
			logout ($2->at(i)->getname());
			$$->push_back($2->at(i));
			if($2->at(i)->getname() == "int" || $2->at(i)->getname() == "float" || $2->at(i)->getname() == "void" || $2->at(i)->getname() == "return")
				logout (" ");
			if($2->at(i)->getname() == ";" || $2->at(i)->getname() == "{" || $2->at(i)->getname() == "}")
					logout ("\n");
		}
		logout ("\n\n");
    }
    ;
statement : var_declaration
	  {
	  	$$ = new vector<smbol_info*>();
	  
        logout("statement : var_declaration\n",line_count);
		for(int i = 0; i < $1->size(); i++){
			logout ($1->at(i)->getname());
			$$->push_back($1->at(i));
			if($1->at(i)->getname() == "int" || $1->at(i)->getname() == "float" || $1->at(i)->getname() == "void")
				logout (" ");
		}
		logout ("\n\n");
	  }
    | expression_statement{
        $$ = new vector<smbol_info*>();
	  	
        logout("statement : expression_statement\n",line_count);
	  	for(int i = 0; i < $1->size(); i++){
			logout ($1->at(i)->getname());
			$$->push_back($1->at(i));
		}
		logout ("\n\n");
    }
    |{table->enterscope("x",7);} compound_statement {table->printall(); table->exitscope();}
    {
        $$ = new vector<smbol_info*>();
	  	
        logout("statement : compound_statement\n",line_count);
	  	for(int i = 0; i < $2->size(); i++){
			logout ($2->at(i)->getname());
			$$->push_back($2->at(i));
			if($2->at(i)->getname() == "int" || $2->at(i)->getname() == "float" || $2->at(i)->getname() == "void" || $2->at(i)->getname() == "return")
				logout (" ");
			if($2->at(i)->getname() == ";" || $2->at(i)->getname() == "{" || $2->at(i)->getname() == "}")
					logout ("\n");
		}
		logout ("\n\n");
    }
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement{
        $$ = new vector<smbol_info*>();
	  	logout("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);
        
	  	logout ($1->getname()+" "+$2->getname());
	  	for(int i = 0; i < $3->size(); i++){
			logout ($3->at(i)->getname());
			$$->push_back($3->at(i));
		}
		for(int i = 0; i < $4->size(); i++){
			logout ($4->at(i)->getname());
			$$->push_back($4->at(i));
		}
		for(int i = 0; i < $5->size(); i++){
			logout ($5->at(i)->getname());
			$$->push_back($5->at(i));
		}
		logout ($6->getname());
		$$->push_back($6);
		for(int i = 0; i < $7->size(); i++){
			logout ($7->at(i)->getname());
			$$->push_back($7->at(i));
			if($7->at(i)->getname() == "int" || $7->at(i)->getname() == "float" || $7->at(i)->getname() == "void" || $7->at(i)->getname() == "return")
				logout (" ");
			if($7->at(i)->getname() == ";" || $7->at(i)->getname() == "{" || $7->at(i)->getname() == "}")
				logout ("\n");
		}
		logout ("\n\n");
    }
    | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE{
        $$ = new vector<smbol_info*>();
	  	
        logout("statement : IF LPAREN expression RPAREN statement\n",line_count);
	  	logout ($1->getname()+" "+ $2->getname());
	  	for(int i = 0; i < $3->size(); i++){
			logout ($3->at(i)->getname());
			$$->push_back($3->at(i));
		}
		logout ($4->getname());
		$$->push_back($4);
		for(int i = 0; i < $5->size(); i++){
			logout ($5->at(i)->getname());
			$$->push_back($5->at(i));
			if($5->at(i)->getname() == "int" || $5->at(i)->getname() == "float" || $5->at(i)->getname() == "void" || $5->at(i)->getname() == "return")
				logout (" ");
			if($5->at(i)->getname() == ";" || $5->at(i)->getname() == "{" || $5->at(i)->getname() == "}")
				logout ("\n");
		}
		logout ("\n\n");

    }
    | IF LPAREN expression RPAREN statement ELSE statement{
        $$ = new vector<smbol_info*>();
	  	
	  	logout("statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);
        logout ($1->getname()+" "+ $2->getname());
	  	for(int i = 0; i < $3->size(); i++){
			logout ($3->at(i)->getname());
			$$->push_back($3->at(i));
		}
		logout ($4->getname());
		$$->push_back($4);
		for(int i = 0; i < $5->size(); i++){
			logout ($5->at(i)->getname());
			$$->push_back($5->at(i));
			if($5->at(i)->getname() == "int" || $5->at(i)->getname() == "float" || $5->at(i)->getname() == "void" || $5->at(i)->getname() == "return")
				logout (" ");
			if($5->at(i)->getname() == ";" || $5->at(i)->getname() == "{" || $5->at(i)->getname() == "}")
				logout ("\n");
		}
		logout ($6->getname());
		$$->push_back($6);
		for(int i = 0; i < $7->size(); i++){
			logout ( $7->at(i)->getname());
			$$->push_back($7->at(i));
			if($7->at(i)->getname() == "int" || $7->at(i)->getname() == "float" || $7->at(i)->getname() == "void" || $7->at(i)->getname() == "return")
				logout (" ");
			if($7->at(i)->getname() == ";" || $7->at(i)->getname() == "{" || $7->at(i)->getname() == "}")
				logout ("\n");
		}
		logout ("\n\n");
    }
    | WHILE LPAREN expression RPAREN statement{
        $$ = new vector<smbol_info*>();
	  	
	  	logout("statement : WHILE LPAREN expression RPAREN statement\n",line_count);
        logout ($1->getname()+" "+$2->getname());
	  	for(int i = 0; i < $3->size(); i++){
			logout ($3->at(i)->getname());
			$$->push_back($3->at(i));
		}
		logout ($4->getname());
		$$->push_back($4);
		for(int i = 0; i < $5->size(); i++){
			logout ($5->at(i)->getname());
			$$->push_back($5->at(i));
			if($5->at(i)->getname() == "int" || $5->at(i)->getname() == "float" || $5->at(i)->getname() == "void" || $5->at(i)->getname() == "return")
				logout (" ");
			if($5->at(i)->getname() == ";" || $5->at(i)->getname() == "{" || $5->at(i)->getname() == "}")
				logout ("\n");
		}
		logout ("\n\n");
    }
    | PRINTLN LPAREN ID RPAREN SEMICOLON{
        $$ = new vector<smbol_info*>();
        logout("statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n",line_count);
        lastsemicolon=line_count;
	  	
		if(table->lookup($3->getname()) == NULL){  // Undeclared error
			
			logout("Error:Undeclared variable " + $3->getname() +"\n",line_count);
            errorout("Error:Undeclared variable " + $3->getname() +"\n",line_count);
            error++;
		}
	  	
        logout ($1->getname()+" "+$2->getname() +" "+ $3->getname() +" "+ $4->getname()+" "+$5->getname()+"\n\n");
	  	$$->push_back($1);
	  	$$->push_back($2);
	  	$$->push_back($3);
	  	$$->push_back($4);
	  	$$->push_back($5);
    }
    | RETURN expression SEMICOLON{
        $$ = new vector<smbol_info*>();
        lastsemicolon=line_count;
	  	
        logout("statement : RETURN expression SEMICOLON\n",line_count);
	  	logout ($1->getname() + " ");
	  	$$->push_back($1);
	  	for(int i = 0; i < $2->size(); i++){
			logout($2->at(i)->getname());
			$$->push_back($2->at(i));
		}
		logout($3->getname() + "\n\n");
		$$->push_back($3);
    }
    ;
expression_statement : SEMICOLON {
        lastsemicolon=line_count;
        logout("expression_statement 	: SEMICOLON\n",line_count);
        logout ($1->getname() + "\n\n");
        $$ = new vector<smbol_info*>();
        $$->push_back($1);
    }			
    | expression SEMICOLON {
        $$ = new vector<smbol_info*>();
       lastsemicolon=line_count;
        logout("expression_statement : expression SEMICOLON \n",line_count);
        for(int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        logout ($2->getname() + "\n\n");
        $$->push_back($2);
    }
    |expression error{
        /*logout("Synnatx error",lastsemicolon+1);
       
        errorout("Syntax error",lastsemicolon+1);*/
        // error++;
    }
    ;
variable : ID {
        $$ = new vector<smbol_info*>();
		
        logout("variable : ID\n",line_count);
		// semantic error-------//
		if(table->lookup( $1->getname()) ==NULL){  // Undeclared error
			
			logout("Error:  Undeclared variable "+$1->getname()+ "\n ",line_count);
            errorout("Error:  Undeclared variable "+$1->getname()+ "\n ",line_count);
            error++;
		}
		else{    // type mismatch error
			smbol_info *temp = table->lookup($1->getname());
			if(temp->getwhichvar() == "array"){
                logout("Error: Type mismatch, "+$1->getname()+ " is an array\n",line_count);
                errorout("Error: Type mismatch, "+$1->getname()+ " is an array\n",line_count);
				
                error++;
			}
			else if(temp->getwhichvar() == "func"){
				logout("Error: Type mismatch, "+$1->getname()+ " is a function\n",line_count);
                errorout("Error: Type mismatch, "+$1->getname()+ " is a function\n",line_count);
				
                error++;
			}
		}
		//-----------//
		logout ($1->getname() +"\n\n");
		$$->push_back($1);

    }		
    | ID LTHIRD expression RTHIRD {
        $$ = new vector<smbol_info*>();
	 	
        logout("variable : ID LTHIRD expression RTHIRD\n",line_count);
		// semantic error-------//
		if(table->lookup($1->getname()) == NULL){    // Undeclared error
            logout("Error: Undeclared variable " + $1->getname() +"\n",line_count);
            errorout("Error: Undeclared variable " + $1->getname() +"\n",line_count);
			error++;
		}
		else{               // not an array
			smbol_info* temp = table->lookup( $1->getname());
			if(temp->getwhichvar()!= "array"){   
                logout("Error: " + $1->getname() +"not an array \n",line_count);
                errorout("Error: " + $1->getname() +"not an array\n",line_count);
                error++;   
				
			}
		}
		if($3->at(0)->gettype() != "CONST_INT"){  // array index not integer
            logout("Error: " + $1->getname() +"Index not integer \n",line_count);
            errorout("Error:" + $1->getname() +"Index not integer \n",line_count);
			error++;
			
		}
		
		//-----------//
	 	logout ($1->getname() +" "+ $2->getname()+" "+$3->at(0)->getname()+" "+$4->getname() + "\n\n");
	 	$$->push_back($1);
	 	$$->push_back($2);
		$$->push_back($3->at(0));
		$$->push_back($4);
    }
    ;
expression : logic_expression {
        $$ = new vector<smbol_info*>();
      
        logout("expression : logic_expression\n",line_count);
        for(int i = 0; i < $1->size(); i++){
            logout ( $1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        logout("\n\n");

    }	
    | variable ASSIGNOP logic_expression {
        $$ = new vector<smbol_info*>();
        
        logout(" expression : variable ASSIGNOP logic_expression\n",line_count);
        //semantic error----------//
        for(int i = 0; i < $3->size(); i++){     //  void function in expression
            if($3->at(i)->gettype() == "ID" && table->lookup($3->at(i)->getname()) != NULL){
                smbol_info* temp = table->lookup( $3->at(i)->getname());
                if(temp->getwhichvar() == "func" && temp->get_var_type() == "VOID"){
                    logout("Error:Void function used in expression\n ",line_count);
                    errorout("Error:Void function used in expression\n ",line_count);
                    error++;
                }
            }
        }
                
        if(table->lookup($1->at(0)->getname()) != NULL){     // float assignment in integer error
            smbol_info *temp = table->lookup($1->at(0)->getname());
            if(temp->get_var_type() == "INT"){
                
                for(int i = 0; i < $3->size(); i++){
                    if($3->at(i)->gettype() == "CONST_FLOAT"){
                        logout("Error: type mismatch\n",line_count);
                        errorout("Error: type mismatch\n",line_count);
                        error++;
                        break;
                    }
                    
                }
            }
        }
        //------------//
        for(int i = 0; i < $1->size(); i++){
            logout ( $1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        logout ($2->getname());
        $$->push_back($2);
        for(int i = 0; i < $3->size(); i++){
            logout ($3->at(i)->getname());
            $$->push_back($3->at(i));
        }
        logout ("\n\n");
    }	
    ;
logic_expression : rel_expression {
        $$ = new vector<smbol_info*>();
       
        logout("logic_expression : rel_expression\n",line_count);
        for(int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        logout ("\n\n");

    }	
    | rel_expression LOGICOP rel_expression {
        $$ = new vector<smbol_info*>();
        logout("logic_expression : rel_expression LOGICOP rel_expression\n",line_count);

        for(int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        logout ($2->getname());
        $$->push_back($2);
        for(int i = 0; i < $3->size(); i++){
            logout($3->at(i)->getname());
            $$->push_back($3->at(i));
        }
        logout ("\n\n");
    }
    | rel_expression UNRECOGNISED_OP rel_expression{
        $$ = new vector<smbol_info*>();
       
        //logout("logic_expression : rel_expression\n",line_count);
        for(int i = 0; i < $1->size(); i++){
            //logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        error++;
        //logout ("\n\n");
    }
    ;
rel_expression	: simple_expression {
        $$ = new vector<smbol_info*>();
        
        logout("rel_expression : simple_expression\n",line_count);
        for(int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        logout ("\n\n");

    }
    | simple_expression RELOP simple_expression	{
        $$ = new vector<smbol_info*>();
        logout(" rel_expression : simple_expression RELOP simple_expression\n",line_count);
 
        for(int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        logout ($2->getname());
        $$->push_back($2);
        for(int i = 0; i < $3->size(); i++){
            logout($3->at(i)->getname());
            $$->push_back($3->at(i));
        }
        logout ("\n\n");
    }
    ;
simple_expression : term {
        $$ = new vector<smbol_info*>();
       
        logout("simple_expression : term\n",line_count);
        for(int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        logout ("\n\n");

    }
    | simple_expression ADDOP term {
        $$ = new vector<smbol_info*>();
        logout("simple_expression : simple_expression ADDOP term\n",line_count);
        
        for(int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
        }
        logout ($2->getname());
        $$->push_back($2);
        for(int i = 0; i < $3->size(); i++){
            logout ($3->at(i)->getname());
            $$->push_back($3->at(i));
        }
        logout ("\n\n");
    }
    ;
term :	unary_expression {
        $$ = new vector<smbol_info*>();
		
        logout("term :	unary_expression\n",line_count);
		for(int i = 0; i < $1->size(); i++){
	 		logout ($1->at(i)->getname());
	 		$$->push_back($1->at(i));
	 	}
	 	logout("\n\n");

    }
    |  term MULOP unary_expression{
        $$ = new vector<smbol_info*>();
     		
            logout("term :  term MULOP unary_expression\n",line_count);
		// semantic error-----------//
		if($2->getname() == "%"){    // mod operand not integer
			if($1->size() == 1 && $3->size() == 1){
				if($1->at(0)->gettype() != "CONST_INT" || $3->at(0)->gettype() != "CONST_INT"){
                    logout("Error:Non-Integer operand on modulus operator\n",line_count);
                    errorout("Error:Non-Integer operand on modulus operator\n",line_count);
					error++;
				}
				else if($3->at(0)->getname() == "0"){
                    logout("Error:Modulus by Zero\n",line_count);
                    errorout("Error:Modulus by Zero\n",line_count);
					error++;
				}
			}
		}
        if($2->getname()=="/"){
            if($3->at(0)->getname()=="0"){
                logout("Eroor: division by 0 \n",line_count);
                errorout("Eroor: division by 0 \n",line_count);
                error++;
            }
        }
			
		for(int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
	 		logout ($1->at(i)->getname());
	 		
	 	}
        $$->push_back($2);
	 	logout ($2->getname());
	 	
	 	for(int i = 0; i < $3->size(); i++){
            $$->push_back($3->at(i));
	 		logout ($3->at(i)->getname());
	 		
	 	}
	 	logout("\n\n");
    }
    ;

unary_expression : ADDOP unary_expression  {
        $$ = new vector<smbol_info*>();
        
        logout("unary_expression : ADDOP unary_expression \n",line_count);
        $$->push_back($1);
        logout ( $1->getname());
        
        for(int i = 0; i < $2->size(); i++){
            $$->push_back($2->at(i));
            logout ($2->at(i)->getname());
            
        }
        logout ("\n\n");

    }
    | NOT unary_expression {
        $$ = new vector<smbol_info*>();
        
        logout("unary_expression : NOT unary_expression \n",line_count);
        $$->push_back($1);
        logout ($1->getname());
        
        for(int i = 0; i < $2->size(); i++){
            $$->push_back($2->at(i));
            logout ($2->at(i)->getname());
            
        }
        logout ("\n\n");
    }
    | factor {
        $$ = new vector<smbol_info*>();
        logout("unary_expression : factor \n",line_count);
        
        for (int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
            logout ($1->at(i)->getname());
           
        }
        logout ("\n\n");
    }
    ;

factor	: variable {
        $$ = new vector<smbol_info*>();
		
        logout("factor  : variable \n",line_count);
		for (int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
	 		logout ($1->at(i)->getname());
	 		
        }
        logout("\n\n");

    }
	| ID LPAREN argument_list RPAREN {
        $$ = new vector<smbol_info*>();
        logout("factor  : ID LPAREN argument_list RPAREN\n",line_count);
		
		//semantic error--------//
		if(table->lookup($1->getname()) == NULL){
            logout("Error: Undeclared function "+ $1->getname() + "\n",line_count);
            errorout("Error: Undeclared function "+ $1->getname() + "\n",line_count);
			error++;
		}
		else{          // function argument check with declaration
			smbol_info* temp = table->lookup( $1->getname());
			if(temp->getwhichvar() != "func"){
                logout("Error:"+$1->getname() +" not a function\n",line_count);
                errorout("Error:"+$1->getname() +" not a function\n",line_count);
				
				error++;
			}
			vector<string> parameter_type;
			for(int i = 0; i < $3->size(); i++){
				if($3->at(i)->gettype() == "ID"){
					if(i != $3->size()-1){
						if($3->at(i+1)->getname() != "["){      // variable
							smbol_info* temp1 = table->lookup( $3->at(i)->getname());
							if(temp1 != NULL)
								parameter_type.push_back(temp1->get_var_type());
						}
						else if($3->at(i+2)->gettype() == "CONST_INT" && $3->at(i+3)->getname() == "]"){   //array
							smbol_info* temp1 = table->lookup( $3->at(i)->getname());
							if(temp1 != NULL)
								parameter_type.push_back(temp1->get_var_type());
						}
					}
					else{       // variable
						smbol_info* temp1 = table->lookup($3->at(i)->getname());
						if(temp1 != NULL)
							parameter_type.push_back(temp1->get_var_type());
					}
				}
				
				else if($3->at(i)->gettype() == "CONST_INT"){
					if(i != 0){
						if($3->at(i-1)->getname() != "["){
							if($3->at(i-1)->getname() == ",")
								parameter_type.push_back("INT");
						}
					}
					else{
						parameter_type.push_back("INT");
					}
				}
				else if($3->at(i)->gettype() == "CONST_FLOAT"){
					if(i != 0){
						if($3->at(i-1)->getname() != "["){
							if($3->at(i-1)->getname() == ",")
								parameter_type.push_back("FLOAT");
						}
					}
					else{
						parameter_type.push_back("FLOAT");
					}
				}
			}
			if(parameter_type.size() != temp->getparamsize()){
                logout("Error: Total number of arguments mismatch in function " + $1->getname() + "\n ",line_count);
				errorout("Error: Total number of arguments mismatch in function " + $1->getname() + "\n ",line_count);
				error++;
			} 
			else{
				for(int i = 0; i < temp->getparamsize(); i++){
					if(parameter_type.at(i) != temp->get_param_at(i)){
                        string s=to_string(i+1);
                        logout("Error: "+s+ "th argument mismatch in function " +$1->getname() +"\n",line_count);
						errorout("Error: "+s+ "th argument mismatch in function " +$1->getname() +"\n",line_count);
						error++;
						break;
					}
				}
			}
		}
		//---------------//
        $$->push_back($1);
		$$->push_back($2);
		logout( $1->getname()+" "+ $2->getname());
		
		for (int i = 0; i < $3->size(); i++){
            $$->push_back($3->at(i));
	 		logout ($3->at(i)->getname());
	 		
  		 }
        $$->push_back($4);
  		logout  ($4->getname() +"\n\n");
		
    }
	| LPAREN expression RPAREN {
        logout("factor  : LPAREN expression RPAREN\n",line_count);
        $$ = new vector<smbol_info*>();
		$$->push_back($1);
		logout ( $1->getname());
		
		for (int i = 0; i < $2->size(); i++){
            $$->push_back($2->at(i));
	 		logout ( $2->at(i)->getname());
	 		
  		 }
        logout ($3->getname() + "\n\n");
        $$->push_back($3);
    }
	| CONST_INT {
        logout("factor : CONST_INT\n",line_count);
        $$ = new vector<smbol_info*>();
		$$->push_back($1);
		logout ($1->getname() + "\n\n");
		
    }
	| CONST_FLOAT {
        logout("factor : CONST_FLOAT\n",line_count);
        $$ = new vector<smbol_info*>();
		$$->push_back($1);
		logout ($1->getname() + "\n\n");
        
    }
	| variable INCOP {
        $$ = new vector<smbol_info*>();
		
        logout("factor  : variable INCOP\n",line_count);
		for (int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
	 		logout( $1->at(i)->getname());
	 		
  		 }
        $$->push_back($2);
        logout($2->getname()+"\n\n");
        
    }
	| variable DECOP{
        $$ = new vector<smbol_info*>();
		
        logout("factor  : variable DECOP\n",line_count);
		for (int i = 0; i < $1->size(); i++){
	 		logout ( $1->at(i)->getname());
	 		$$->push_back($1->at(i));
  		 }
        logout ($2->getname() +"\n\n");
        $$->push_back($2);
    }
	;
argument_list : arguments{
        logout("argument_list : arguments\n",line_count);
        $$ = new vector<smbol_info*>();
        
        for (int i = 0; i < $1->size(); i++){
            logout ($1->at(i)->getname());
            $$->push_back($1->at(i));
            }
            logout ("\n\n");

    }
    | {
        $$ = new vector<smbol_info*>();
        logout("argument_list : \n\n",line_count);
        
    }
    ;
arguments : arguments COMMA logic_expression {
        logout("arguments : arguments COMMA logic_expressionn\n",line_count);
        $$ = new vector<smbol_info*>();
        
        for (int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
            logout ($1->at(i)->getname());
            
        }
        $$->push_back($2);
        logout ($2->getname());
       
        for (int i = 0; i < $3->size(); i++){
            $$->push_back($3->at(i));
            logout ($3->at(i)->getname());
        
        }
        logout ("\n\n");

    }
    | logic_expression {
        logout("arguments  : logic_expression\n",line_count);
        $$ = new vector<smbol_info*>();
            
        for (int i = 0; i < $1->size(); i++){
            $$->push_back($1->at(i));
            logout ($1->at(i)->getname());
            
        }
        logout ("\n\n");
    }
    ;




%%
int main(int argc,char *argv[])
{
    ofstream file2("1805063_log.txt");
    file2.close();
    ofstream file3("1805063_error.txt");
    file3.close();
    table->enterscope("1",7);

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
	//yylineno=1;
	//yylex();
    yyparse();
    table->printall();

    ofstream f2;
    f2.open("1805063_log.txt",ios::app);
    f2<<"Total Line: "<<line_count-1<<endl;
    f2<<"Total Error: "<<error<<endl;
    
    f2.close();

    

	fclose(yyin);
   
	return 0;



    
}

