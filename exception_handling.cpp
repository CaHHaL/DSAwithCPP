// You are using GCC
//exception handling
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int x=a-b;
    try{
        if(x!=0){
            cout<<"Result(a/x)="<<a/x<<endl;
        }else{
            throw(x);
        }
    }catch(int x){
        cout<<"exception caught "<<x<<endl;
    }
    cout<<"end";
}


//Exception handling in array
#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5};
    try{
        int i=0;
        while(1){
            cout<<a[i]<<endl;
            i++;
            if(i==5){
                throw i;
            }
        }}catch(int j)
        {
            cout<<"array out of bounds "<<j;
        }
    
}