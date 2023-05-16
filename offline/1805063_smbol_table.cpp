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
class scopetable{
    string id;
    int length;
    smbol_info ** bucketlist;
    scopetable * parent;
    int inner_sc_no=0;

    public:
    scopetable(){

    }
    int getinner_sc_no(){
        return inner_sc_no;
    }
    void incr_inner_sc_no(){
        inner_sc_no++;
    }
    scopetable(string id,int length,scopetable *parent){
        this->id=id;
        this->length=length;
        bucketlist = new smbol_info*[length];
        for(int i=0;i<length;i++){
            bucketlist[i]=NULL;
        }
        this->parent=parent;
        
    }
    ~scopetable(){
        for(int i=0;i<length;i++){
            smbol_info * tem=bucketlist[i];
            while (tem!= NULL)
            {
               smbol_info * t=tem;
               tem=t->getnext();
               delete t;
            }
            
        }
        delete[] bucketlist;
    }

    int hash(string s){
        int hash = 0;
        int l=s.size();
        for(int i=0;i<l;i++ )
        {
            hash = s[i] + (hash << 6) + (hash << 16) - hash;
        }
        return hash % length;
        
    }

    string getid(){
        return id;
    }
    int getlength(){
        return length;
    }
    scopetable * getparent(){
        return parent;
    }
    void setparent(scopetable * parent){
        this->parent=parent;
    }

    smbol_info* lookup(string s){

        int indx=hash(s);
        int pos=0;
        smbol_info * temp=bucketlist[indx];
        if(temp == NULL){
            //cout<<s<<" not found"<<endl;
            return NULL;
        }
        while(temp!=NULL){
            
            if(temp->getname()== s){

                cout<<s<<" found in scope table# "<<id<<"position "<<indx<<","<<pos<<endl;
                return temp;

            }

            temp=temp->getnext();
            pos++;
        }
        return NULL;
        
    }

    bool insert(string name,string type){
        int pos=0;
        smbol_info* r=lookup(name); 
        if(r!=NULL){
            cout<<"already exsists in the scope"<<endl;
            return false;
        }
        else{
            int indx=hash(name);
            cout<<"inserted at scope table# "<<id<<"position "<<indx<<",";
            smbol_info * sm=new smbol_info(name,type);
            smbol_info * temp=bucketlist[indx];
            if(temp==NULL){
                bucketlist[indx] = sm;
                cout<<pos<<endl;
                return true;
                
            }
            else{
                pos=1;
                while(temp->getnext()!=NULL){
                    temp=temp->getnext();
                    pos++;

                }
                temp->setnxt(sm);
                cout<<pos<<endl;
                return true;
            }


            
        }
        
    }
    bool deletesm(string name){
        smbol_info* temp=lookup(name);
        if(temp==NULL){
            cout<<"not found"<<endl;
            return false;
        }
        else{
            int indx=hash(name);
            int pos =0;
            smbol_info *t=bucketlist[indx];
            smbol_info *prev=NULL;
            while (t!=NULL)
            {
                if(t->getname()==name){
                    break;
                }
                prev=t;
                t=t->getnext();
                pos++;

                /* code */
            }
            if(prev==NULL){
                bucketlist[indx]=t->getnext();
                
            }
            else{
                
                prev->setnxt(t->getnext());
                
            }
            delete t;
            cout<<"deleted from scope table# "<< id<<"position "<<indx<<","<<pos<<endl;
            return true;
            
        }


       
    }

    void print(){
        cout<<"scopetable# "<<id<<endl;

        for(int i=0;i<length;i++){
            cout<<i<<"-->";
            smbol_info * temp=bucketlist[i];

            while(temp!=NULL){
                cout<<"<"<<temp->getname()<<" : "<<temp->gettype()<<">";

                temp=temp->getnext();
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }



};

class smbol_table{
    scopetable * current;

    public:
    smbol_table(){
        current=NULL;
    }
    ~smbol_table(){

        scopetable * tem=current;
        while(tem!=NULL){
            scopetable * t=tem;
            tem=t->getparent();
            t->~scopetable();
        }
        
    }
     string getcurid(){
        return current->getid();
    }
    void enterscope(string id,int length){
        if(current==NULL){
            scopetable * scope=new scopetable(id,length,current);
            current=scope;
            if(current==NULL){
                cout<<"stml"<<endl;
            }
            cout<<"new scopetable with id# "<<id<<endl;
        }
        else{
            current->incr_inner_sc_no();
            int sc_no=current->getinner_sc_no();
            string p_id=current->getid();
            //cout<<p_id<<endl;
            string sid=to_string(sc_no);
            string scid=p_id+"."+sid;
            scopetable * scope=new scopetable(scid,length,current);
            current=scope;
            cout<<"new scopetable with id# "<<current->getid()<<endl;


        }
        

        return;
    }

    void exitscope(){
        if(current==NULL){
            cout<<"no scope "<<endl;
            return;
        }
        else{
            cout<<"scope with id# "<<current->getid()<<" removed"<<endl;
            scopetable *t=current;
            current=t->getparent();
            t->~scopetable();
        }

    }
    bool insert(string name,string type){
        if(current==NULL){
            cout<<"no scope to insert into"<<endl;
            return false;
        }
        else{
            bool res=current->insert(name,type);
            return res;
        }

    }

    bool deletesm(string name){
        if(current==NULL){
            cout<<"no scope to delete from"<<endl;
            return false;

        }
        else{
            bool res=current->deletesm(name);
            return res;
        }
    }
    smbol_info * lookup(string name){
        if(current==NULL){
            cout<<"no scope to look up"<<endl;
            return NULL;
        }
        scopetable * temp=current;
        smbol_info * res=NULL;
        while(temp!=NULL){
            res=temp->lookup(name);
            if(res!=NULL){
                break;
            }

            temp=temp->getparent();
        }
        return res;
    }

   

    void printcurrent(){
        if(current==NULL){
            cout<<"no scope in the symbol table"<<endl;
            return;

        }
        else{
            current->print();
            return ;
        }
    }
    void printall(){
        if(current==NULL){
            cout<<"no scope in the symbol table"<<endl;
            return;
        }
        scopetable * temp=current;
        while(temp!=NULL){
            temp->print();
            cout<<endl;
            temp=temp->getparent();
        }
        return;
    }



};

int main(){
    FILE * input;
    FILE * out;
    input=freopen("in2.txt","r",stdin);
    out=freopen("out3.txt","w",stdout);
    int length;
    cin>>length;
    string cm,cm1;
    string name,type;
    smbol_table * st=new smbol_table();
    st->enterscope("1",length);
    while (true)
    {
        if(feof(stdin)){
            cout<<"break"<<endl;
            break;
        }
        cin>>cm;
        if(cm=="I"){
            cin>>name;
            cin>>type;
            cout<<cm<<" "<<name<<" "<<type<<endl;
            st->insert(name,type);

        }
        else if(cm=="D"){
            cin>>name;
            bool r=st->deletesm(name);
            if(!r){
                cout<<name<<" not found"<<endl;
            }
            
        }
        else if(cm=="L"){
            cin>>name;
            cout<<cm<<" "<<name<<endl;
            smbol_info * sm=st->lookup(name);

            if(sm==NULL){
                cout<<"not found"<<endl;
            }
        }
        else if(cm=="S"){
            cout<<cm<<endl;
            
            st->enterscope("d",length);
            
        }
        else if(cm=="E"){
            cout<<cm<<endl;
            st->exitscope();
            
        }
        else if(cm=="P"){
            cin>>cm1;

            cout<<cm<<" "<<cm1<<endl;
            if(cm1=="A"){
                st->printall();
            }
            else if(cm1=="C"){
                st->printcurrent();

            }
        }
        
        else{
            cout<<"end"<<endl;
            break;
        }
    }
    
    st->~smbol_table();

}


