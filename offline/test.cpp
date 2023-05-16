#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a;

    vector <int> v;
    for(int i=0;i<10;i++){
         cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
   
    cout<<a<<"hello"<<endl;
}