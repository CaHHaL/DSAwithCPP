// You are using GCC
//template
#include<iostream>
using namespace std;
template<class T>
T minNum(T num1,T num2){
    if(num1>num2){
        return num2;
    }else{
        return num1;
    }
}
int main(){
    int num1=3;
    int num2=5;
    cout<<"Min of"<<num1<<"&&"<<num2<<"="<<minNum<int>(num1,num2)<<endl;
    float num3=52.6;
    float num4=51.6;
     cout<<"Min of"<<num3<<"&&"<<num4<<"="<<minNum<float>(num3,num4)<<endl;
}
//template sum
#include<iostream>
using namespace std;
#define MAX 5
template<class Type>
Type sum(Type A[]){
    Type Total=0;
    for(int i=0;i<MAX;i++){
        Total+=A[i];
        return Total;
    }
}
template<class Type>
void read(Type A[]){
    for(int i=0;i<MAX;i++){
        cin>>A[i];
    }
}
int main(){
    int Array[MAX];
    float Array1[MAX];
    cout<<"Enter the integer element array: "<<endl;
    read<int>(Array);
    cout<<"Sum of elements = "<<sum<int>(Array)<<endl;
    cout<<"Enter the float array elements :"<<endl;
    read<float>(Array1);
    cout<<"Sum of elements = "<<sum<float>(Array1)<<endl;
    
}

//func template with multiply parameter
#include<iostream>
using namespace std;
template<class T1,class T2>
void multiply(T1 num1,T2 num2){
    cout<<num1*num2;
}
int main(){
    int num1=3;
    float num2=4.5;
    cout<<"Product of num1 And num2 is ";
    multiply<int,float>(num1,num2);
    cout<<endl;
    multiply<int,int>(2,2);
    float num3=7.8;
    int num4=3;
    cout<<"Product of num3*num4 = ";
    multiply<float,int>(num3,num4);
    cout<<endl;
    multiply<float,float>(2.3,4.5);
    return 0;
    
}