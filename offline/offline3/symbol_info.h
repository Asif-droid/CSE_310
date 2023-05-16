#include<iostream>
#include <fstream>
using namespace std;

class smbol_info{
    private:
    string name;
    string type;

    smbol_info *next;

    public:
    smbol_info(){

    }
    smbol_info(string name,string type){
        this->name=name;
        this->type=type;
        next=NULL;
    }
    ~smbol_info(){

    }

    void setname(string name){
        this->name=name;
    }
    void settype(string type){
        this->type=type;
    }
    void setnxt(smbol_info *next){
        this->next=next;
    }
    string getname(){
        return name;
    }
    string gettype(){
        return type;
    }
    smbol_info* getnext(){
        return next;
    }

};