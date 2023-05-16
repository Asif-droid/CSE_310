#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstdio>
using namespace std;

int main(){
    ifstream filein("t.txt");
    ofstream of;
    of.open("tes.txt",ios::app);
    string s;
    int i=0;
    while(i<10){
       
        
        
            cout<<"iterations "+i<<endl;
            of<<"iterations "+i<<endl;
        
        i++;
    }
    of.close();

}