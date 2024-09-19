// You are using GCC
//printing array
#include<stdio.h>
void PrintArray(int* arr, int n){
    for(int i=0;i<n;i++){
        printf("%d \n",arr[i]);
    }    
    
}
    
void PrintReverse(int* arr,int n){
    for(int i=n-1;i>0;i++){
        printf("%d \n",arr[i]);
    } 
} 

void PrintSum(int* arr,int n){
   int sum=0;
    for(int i=0;i<n;i++){
    sum=sum+arr[i];
    printf("%d \n",sum);
    }
}

void ReverseArray(int* arr,int n ,int* arr2){
    for(int i=0;i<n;i++){
        arr2[i]=arr[i];
        int a=n;
        arr[i]=arr2[a];
        a--;
        printf("%d",arr[i]);
    }
    
}
void Reversemethod2(int* arr,int n){
    for(int i=0;i<n;i++){
        int s=0;
        int e=n-1;
        int sample=arr[s];
        arr[s]=arr[e];
        s++;
        e--;
        printf("%d",arr[i]);
        
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
     int arr2[n];
    PrintArray(arr,n);
    PrintReverse(arr,n);
    PrintSum(arr,n);
    ReverseArray(arr,n,arr2);
    Reversemethod2(arr,n);
 return 0;
}




#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d ",&arr[i]);
    }
     int count=0;
     int sum=0;
     
    for(int i=0;i<N;i++){
        if(i%2==0){
            count++;
            sum=sum+arr[i];
        }
    }
    printf("%d",sum/count);
 return 0;
}




// You are working on a mathematics application that requires merging two sorted lists of numbers into a single sorted list without any duplicates. Your task is to write a program that performs this merging operation on two lists of numbers.



// Your program should merge the numbers from the first and second lists into a single sorted list, removing any duplicate numbers. The merged list should contain all the unique numbers, arranged in ascending order.



// After merging the lists, your program should output the numbers in the merged list, according to the initial array.



// Example



// Input:

// 4

// 1 3 5 7

// 5

// 2 4 6 8 9

// Output:

// 1 2 3 4

// 5 6 7 8 9

// Explanation:

// The first list has 4 numbers [1, 3, 5, 7], and the second list has 5 numbers [2, 4, 6, 8, 9]. After sorting, the list becomes [1, 2, 3, 4, 5, 6, 7, 8, 9] with duplicates removed and sorted in ascending order. After merging, the first list becomes [1, 2, 3, 4] and the second list becomes [5, 6, 7, 8, 9].



// Company Tags: HCL

// Input format :
// The first line of input consists of an integer n, representing the size of the first sorted array.

// The second line of input consists of n space-separated integers, representing the elements of the first sorted array.

// The third line of input consists of an integer m, representing the size of the second sorted array.

// The fourth line of input consists of m space-separated integers, representing the elements of the second sorted array.

// Output format :
// After sorting the array, the first line of output prints the first n sorted numbers, and the second line prints the last m numbers.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n, m ≤ 10

// 1 ≤ array elements ≤ 25

// Sample test cases :
// Input 1 :
// 3
// 1 2 3
// 2
// 4 5
// Output 1 :
// 1 2 3 
// 4 5 
// Input 2 :
// 4
// 1 3 5 7
// 5
// 2 4 6 8 9
// Output 2 :
// 1 2 3 4 
// 5 6 7 8 9 



// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int n1;
    cin>>n1;
    int arr[n1];
    for(int i=0;i<n1;i++){
        cin>>arr[i];
    }
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int j=0;j<n2;j++){
        cin>>arr2[j];
    }
    for(int k=1;k<n1+1;k++)
    {
        cout<<k<<" ";
    }
    cout<<endl;
    for(int l=n1+1;l<n1+n2+1;l++)
    {
        cout<<l<<" ";
    }
}



// At a university, two student clubs, "Tech Wizards" and "Creative Minds," have decided to merge and form a new club called "Innovative Thinkers." 



// As part of the merger process, the club leaders, Alex and Sarah, need to create a program that merges the member lists of the two clubs and identifies the unique members in the merged list. The program takes two arrays, arr1, and arr2, as inputs with sorted member IDs. Each array represents the member IDs of the respective clubs. Help Alex and Sarah.



// Company Tags: Capgemini

// Input format :
// The first line of input consists of an integer n, representing the size of the first array (Tech Wizards).

// The second line of input consists of n space-separated integers, representing the member IDs of the first array.

// The third line of input consists of an integer m, representing the size of the second array (Creative Minds).

// The fourth line of input consists of m space-separated integers, representing the member IDs of the second array.

// Output format :
// The output displays the unique member IDs from the merged array, separated by a space.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n, m ≤ 10

// 1 ≤ member IDs ≤ 50

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// 7
// 4 5 6 6 7 7 8
// Output 1 :
// 1 2 3 4 5 6 7 8 
// Input 2 :
// 3
// 2 2 2
// 4
// 3 4 5 6
// Output 2 :
// 2 3 4 5 6 


#include<iostream>
using namespace std;
void Merging(int* arr1,int n1,int* arr2,int n2,int* arr3){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr3[k++]=arr1[i++];
        }else if(arr1[i]>=arr2[j]){
            arr3[k++]=arr2[j++];
        }
    }
    while(i<n1){
        arr3[k++]=arr1[i++];
    }
    while(j<n2){
        arr3[k++]=arr2[j++];
    }
    int count=n1+n2;
    for(int l=0;l<count;l++){
       if(arr3[l]!=arr3[l+1]){
        cout<<arr3[l]<<" ";
       }
    }
}
int main(){
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int j=0;j<n2;j++){
        cin>>arr2[j];
    }
    int arr3[n1+n2];
    Merging(arr1,n1,arr2,n2,arr3);
}




// You are working on a mathematics application that requires merging two sorted lists of numbers into a single sorted list without any duplicates. Your task is to write a program that performs this merging operation on two lists of numbers.



// Your program should merge the numbers from the first and second lists into a single sorted list, removing any duplicate numbers. The merged list should contain all the unique numbers, arranged in ascending order.



// After merging the lists, your program should output the numbers in the merged list, according to the initial array.



// Example



// Input:

// 4

// 1 3 5 7

// 5

// 2 4 6 8 9

// Output:

// 1 2 3 4

// 5 6 7 8 9

// Explanation:

// The first list has 4 numbers [1, 3, 5, 7], and the second list has 5 numbers [2, 4, 6, 8, 9]. After sorting, the list becomes [1, 2, 3, 4, 5, 6, 7, 8, 9] with duplicates removed and sorted in ascending order. After merging, the first list becomes [1, 2, 3, 4] and the second list becomes [5, 6, 7, 8, 9].



// Company Tags: HCL

// Input format :
// The first line of input consists of an integer n, representing the size of the first sorted array.

// The second line of input consists of n space-separated integers, representing the elements of the first sorted array.

// The third line of input consists of an integer m, representing the size of the second sorted array.

// The fourth line of input consists of m space-separated integers, representing the elements of the second sorted array.

// Output format :
// After sorting the array, the first line of output prints the first n sorted numbers, and the second line prints the last m numbers.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n, m ≤ 10

// 1 ≤ array elements ≤ 25

// Sample test cases :
// Input 1 :
// 3
// 1 2 3
// 2
// 4 5
// Output 1 :
// 1 2 3 
// 4 5 
// Input 2 :
// 4
// 1 3 5 7
// 5
// 2 4 6 8 9
// Output 2 :
// 1 2 3 4 
// 5 6 7 8 9 



#include<iostream>
using namespace std;
int main(){
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int j=0;j<n2;j++){
        cin>>arr2[j];
    }
    int arr3[n1+n2];
    int k=0,l=0,m=0;
    while(k<n1 && l<n2){
        if(arr1[k]<arr2[l]){
            arr3[m++]=arr1[k++];
        }else if(arr1[k]>arr2[l]){
            arr3[m++]=arr2[l++];
        }
    }
    while(k<n1){
        arr3[m++]=arr1[k++];
    }
    while(l<n2){
        arr3[m++]=arr2[l++];
    }
    for(int n=0;n<n1;n++){
        cout<<arr3[n]<<" ";
    }
    cout<<endl;
    for(int o=n1;o<n2+n1;o++){
        cout<<arr3[o]<<" ";
    }
    
}





// Pooja is a teacher who recently conducted two exams for her students, "Mathematics" and "Science." She is working on a program to merge the scores of both exams and identify the maximum score achieved by any student.



// The program takes two arrays, mathScores, and scienceScores, as inputs. Each array represents the scores of the respective subjects for all the students. Pooja wants to combine the arrays and find the maximum score obtained by any student in both exams.



// Company Tags: CTS

// Input format :
// The first line of input consists of an integer n, representing the number of math scores.

// The second line of input consists of n space-separated integers, representing the math scores.

// The third line of input consists of an integer m, representing the number of science scores.

// The fourth line of input consists of m space-separated integers, representing the science scores.

// Output format :
// The output displays an integer, representing the maximum score achieved by any student in both exams.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n, m ≤ 10

// 1 ≤ scores ≤ 110

// Sample test cases :
// Input 1 :
// 6
// 1 2 3 4 5 2
// 7
// 4 5 6 7 8 6 6
// Output 1 :
// 8
// Input 2 :
// 3
// 2 2 2
// 4
// 3 4 5 6
// Output 2 :
// 6


#include<iostream>
using namespace std;
int main(){
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int j=0;j<n2;j++){
        cin>>arr2[j];
    }
    int m=0;
    int temp2=arr2[0];
    while(m<n2){
        if(temp2<arr2[m]){
                temp2=arr2[m];
            }
            m++;
    }
    int n=0;
    int temp1=arr1[0];
    while(n<n1){
        if(temp1<arr1[n]){
                temp1=arr1[n];
            }
            n++;
    }
     if(temp1>temp2){
        cout<<temp1;
    }else{
        cout<<temp2;
    }
    
}



// Banu wants to find the number of elements less than or equal to a given key in a sorted array. 



// Help her write a program that takes the array, the size of the array, and the key as input and returns the count of such elements, using the binary search technique.



// Company Tags: Accenture

// Input format :
// The first line of input consists of the integer n, the size of the array.

// The second line consists of n space-separated integers, representing the elements of the sorted array.

// The third line consists of an integer k.

// Output format :
// The output prints the count of elements in the array that are less than or equal to the given value k.

// Code constraints :
// 1 ≤ n ≤ 10

// -100 ≤ elements of the array ≤ 100

// Sample test cases :
// Input 1 :
// 6
// 1 2 4 5 8 10
// 9
// Output 1 :
// 5
// Input 2 :
// 5
// 11 15 19 23 25
// 25
// Output 2 :
// 5
// Input 3 :
// 3
// -1 0 3
// -9
// Output 3 :
// 0

// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int count=0;
    for(int j=0;j<n;j++){
        if(k>=arr[j]){
            count++;
        }
    }
    cout<<count;
}



// Tom is writing a story and wants to check if a particular word is present in a given sentence. Help Tom by writing a program that determines whether a specific word is found within the sentence. Use linear search.



// Company Tags: Capgemini

// Input format :
// The first line of input consists of a string representing the sentence to be searched.

// The second line consists of the word to search for in the sentence.

// Output format :
// The output prints whether the given word is present in the sentence or not.



// Refer to the sample output for the exact format.

// Code constraints :
// The maximum length of the input sentence is 1000 words.

// Sample test cases :
// Input 1 :
// Constellations of stars, murals on city walls
// stars
// Output 1 :
// The word 'stars' is present in the given sentence.
// Input 2 :
// Constellations of Stars, murals on city walls
// stars
// Output 2 :
// The word 'stars' is not present in the given sentence


// You are using GCC
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    string word;
    getline(cin,word);
    int found=str.find(word);
    // cout<<found;
    if(found!=-1){
        cout<<"The word '"<<word<<"' is present in the given sentence.";
    }else{
        cout<<"The word '"<<word<<"' is not present in the given sentence.";
    }
}



// Lucas is analyzing a sorted list of numbers and wants to find the first and last occurrences of a specific target value in the list. 



// Given a sorted array of integers and a target value, write a program using binary search to find the indices of the first and last occurrences of the target value. If the target value is not found in the array, indicate that as well.

// Input format :
// The first line of input consists of n, the number of elements in the list.

// The second line consists of n elements, separated by space.

// The third line consists of the target value t.

// Output format :
// If the target value is found, print the index of the first and last occurrence. The index starts from 0.

// If the target value is not found, print "Target value [t] is not found in the array."



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 25

// 1 ≤ elements, t ≤ 100

// Sample test cases :
// Input 1 :
// 6
// 12 24 24 37 41 53
// 24
// Output 1 :
// The first occurrence of 24 is at index 1
// The last occurrence of 24 is at index 2
// Input 2 :
// 6
// 12 24 24 37 41 53
// 52
// Output 2 :
// Target value 52 is not found in the array
// Input 3 :
// 6
// 12 24 25 37 41 53
// 37
// Output 3 :
// The first occurrence of 37 is at index 3
// The last occurrence of 37 is at index 3


#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int s,e;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            s=i;
            count++;
            break;
        }
    }
    for(int j=n;j>0;j--){
        if(arr[j]==k){
            e=j;
            break;
        }
    }
    
        if(count>=1){
            cout<<"The first occurrence of "<<k<<" is at index "<<s<<endl;
            cout<<"The last occurrence of "<<k<<" is at index "<<e<<endl;
        }else{
            cout<<"Target value "<<k<<" is not found in the array";
        }
    
    
}



// Given an array of integers, implement a recursive linear search algorithm to find the index of a target element. The program should read the number of elements in the array, the elements themselves, and the target element to search for. If the target element is found, the program should output its index; otherwise, it should indicate that the element is not present. 

// Input format :
// The first line of input consists of an integer N, representing the number of elements.

// The second line consists of N space-separated integers representing the elements.

// The third line consists of an integer d, representing the element to be searched.

// Output format :
// If the target element d is found in the array, print "Element d is present at index X" where X is the index of the target element. The index starts from 0.

// Otherwise, print "Element d is not present".



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 100

// 1 ≤ elements ≤ 105

// 1 ≤ d ≤ 105

// Sample test cases :
// Input 1 :
// 5
// 40 20 50 30 10
// 30
// Output 1 :
// Element 30 is present at index 3
// Input 2 :
// 5
// 40 20 50 30 10
// 80
// Output 2 :
// Element 80 is not present


// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    int arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    int b;
    cin>>b;
    int pos;
    int count=0;
    for(int i=0;i<a;i++){
        if(arr[i]==b){
            pos=i;
            count++;
            break;
        }
    }
    if(count!=0){
        cout<<"Element "<<b<<" is present at index "<<pos;
    }else{
        cout<<"Element "<<b<<" is not present";
    }
}





// Kishen needs to calculate the time difference between two given times. Write a program for Kishen that defines a Time structure and calculates the difference between two times input by the user. The program should output the difference in the format HH:MM:SS, with zero padding for single-digit values.

// Input format :
// The program will take two lines of input, each representing a time in the format HH:MM:SS.

// The first line represents the first time T1.
// The second line represents the second time T2.
// Output format :
// The output prints the difference between the two times in the format HH:MM:SS, with zero padding for single-digit hours, minutes, and seconds.



// Refer to the sample output for formatting specifications.

// Code constraints :
// T1 > T2

// Sample test cases :
// Input 1 :
// 12:34:55
// 8:12:15
// Output 1 :
// 04:22:40
// Input 2 :
// 06:45:30
// 01:30:15
// Output 2 :
// 05:15:15



// You are using GCC
#include<iostream>
#include<iomanip>
using namespace std;
struct Time{
    int hours;
    int minutes;
    int seconds;
};
Time calcDifference(Time t1,Time t2){
    Time result;
    int seconds1,seconds2,totalSeconds;
    seconds1=t1.hours*3600+t1.minutes*60+t1.seconds;
    seconds2=t2.hours*3600+t2.minutes*60+t2.seconds;
    totalSeconds=(seconds1>seconds2)?(seconds1-seconds2):(seconds2-seconds1);
    result.hours=totalSeconds/3600;
    result.minutes=(totalSeconds%3600)/60;
    result.seconds=totalSeconds%60;
    return result;
}
int main(){
   Time t1,t2,diff;
   char colon;
   cin>>t1.hours>>colon>>t1.minutes>>colon>>t1.seconds;
   cin>>t2.hours>>colon>>t2.minutes>>colon>>t2.seconds;
   diff=calcDifference(t1,t2);
   cout<<setfill('0')<<setw(2)<<diff.hours<<":"<<setw(2)<<diff.minutes<<":"<<setw(2)<<diff.seconds<<endl;
   return 0;
   
    
    
}