// You are using GCC
//Heap datatype
//insertion
#include<iostream>
using namespace std;
#define MAX 100
int heap[MAX];
int heapSize=0;
void insert(int value){
    if(heapSize>=MAX){
        cout<<"Heap is full"<<endl;
        return;
    }
    heap[heapSize]=value;
    int current =heapSize;
    heapSize++;
    //heapify the element upwards
    while(current>0 && heap[(current-1)/2]<heap[current]){
    //swap teh current element with its parent
    int temp=heap[(current-1)/2];
    heap[(current-1)/2]=heap[current];
    heap[current]=temp;
    //move up to the current
    current=(current-1)/2;
    }
}
void display(){
    for(int i=0;i<heapSize;i++){
        cout<<heap[i]<<" ";
    }
}
int main(){
   insert(1);
   insert(2);
   insert(3);
   insert(4);
   insert(5);
   insert(6);
   display();
   cout<<endl;
   insert(7);
   insert(8);
   display();
   
}