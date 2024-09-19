// William is a software developer working on a C++ program to manage student records. He needs to update a student's age dynamically using a member pointer and display both the current and updated age. Help him with a suitable program.

// Input format :
// The first line of input consists of the name of the student.

// The second line of input consists of the age of the student.

// The third line of input consists of the age to be updated.

// Output format :
// The first line of output displays the current or input age of the student.

// The second line of output displays the updated age of the student.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 3 ≤ length of the name ≤ 60

// 17 ≤ age ≤ 26

// Sample test cases :
// Input 1 :
// sandeep
// 20
// 23
// Output 1 :
// Current age: 20
// Updated age: 23
// Input 2 :
// John Doe
// 21
// 23
// Output 2 :
// Current age: 21
// Updated age: 23


// You are using GCC
#include<iostream>
using namespace std;
void Change(int* n,int* p){
    cout<<"Current age: "<<*n<<endl;
    *n=*p;
    cout<<"Updated age: "<<*n;
}
int main(){
    string name;
    getline(cin,name);
    int n;
    cin>>n;
    int p;
    cin>>p;
    Change(&n,&p);
}



// Jane has a collection of numbers and wants to determine the largest and smallest elements within it. Write a program that reads the size of her collection and the elements, then finds and prints the largest and smallest elements.

// Input format :
// The first line of input consists of an integer n, representing the number of elements in the collection.

// The second line consists of n space-separated integers, representing the elements in Jane's collection.

// Output format :
// The first line of output prints "The largest element is: " followed by the largest element in the collection.

// The second line prints "The smallest element is: " followed by the smallest element in the collection.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ elements in collection ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 89 68 57 54 25
// Output 1 :
// The largest element is: 89
// The smallest element is: 25
// Input 2 :
// 10
// 78 96 75 63 62 45 52 21 23 28 
// Output 2 :
// The largest element is: 96
// The smallest element is: 21


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
    int larg,small;
    int sm,lm;
    for(int i=0;i<n;i++){
        int larg=0;
        int small=0;
        for(int j=0;j<n;j++){
            if(arr[i]>arr[j]){
                larg++;
                if(larg==n-1){
                    
                    lm=arr[i];
                }
            }
            if(arr[i]<arr[j]){
                small++;
                if(small==n-1){
                   sm=arr[i];
                }
            }
        }
    }
    cout<<"The largest element is: "<<lm<<endl;
    cout<<"The smallest element is: "<<sm<<endl;
}


// Peter is developing a program to filter out non-Fibonacci numbers from a list of integers. He has created a class named NonFibonacciElements to achieve this task. Given an array of integers, write a program inside this class to identify and print all elements that are not Fibonacci numbers.

// Input format :
// The first line of input consists of an integer N, representing the number of elements in the array.

// The second line consists of N space-separated integers, representing the array elements.

// Output format :
// The output prints all elements from the input array that are not Fibonacci numbers, separated by a space.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ array elements ≤ 1000

// Sample test cases :
// Input 1 :
// 7
// 1 5 3 8 9 13 4
// Output 1 :
// 9 4 
// Input 2 :
// 8
// 53 68 94 91 95 2 97 82
// Output 2 :
// 53 68 94 91 95 97 82 
// You are using GCC
#include<iostream>
#include<cmath>
using namespace std;
class NonFibonacciElements{
    public:
    void Non(int temp){
            int f1=0,f2=2,sum=0,dec=1,ss=0,pp=0;
            for(int i=0;sum<=temp;i++){
                 
                 cout<<sum<<" ";
                 
                 sum=f1+f2;
                 ss++;
                 if(temp==sum){
                    break;
                 }else{
                     pp++;
                 }
            }
            if(ss==pp){
                cout<<temp<<" ";
            }
        }
    
};
bool isPerfectSquare(int x){
    if(x<0){
        return false;
    }
    int s=(int)sqrt(x);
    return s*s==x;
}
bool isFibonacci(int n){
    if(n<0){
        return false;
    }
    int x1=5*n*n+4;
    int x2=5*n*n-4;
    return isPerfectSquare(x1) || isPerfectSquare(x2);
}
void filterNonFibonacci(int arr[],int size){
    for(int i=0;i<size;++i){
        if(!isFibonacci(arr[i])){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}
int main(){
  int n;
    NonFibonacciElements f;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  filterNonFibonacci(arr,n);

    
}



// Mandy is analyzing data stored in matrices and needs to determine the number of rows that contain at least one zero element. Help her with a program to count and print this information.

// Input format :
// The first line of input consists of two space-separated integers R and C, denoting the number of rows and columns in the matrix, respectively.

// The next R lines contain C space-separated integers each, representing the elements of each row in the matrix.

// Output format :
// The output displays an integer, representing the number of rows in the matrix that contain at least one zero element.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ R, C ≤ 10

// 0 ≤ array elements ≤ 100

// Sample test cases :
// Input 1 :
// 3 4
// 1 2 3 0
// 5 0 7 8
// 9 5 4 1
// Output 1 :
// 2
// Input 2 :
// 3 3
// 3 0 3
// 9 8 0
// 0 3 1 
// Output 2 :
// 3
// Input 3 :
// 2 2
// 3 3
// 4 4
// Output 3 :
// 0
// Input 4 :
// 2 3
// 12 89 46
// 0 65 0
// Output 4 :
// 1



// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int r;
    int c;
    cin>>r>>c;
    int arr[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
        
    }
    int count=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==0){
                count++;
                
            }
        }
    }
    cout<<count;
    
    
}




// Vijay wants to write a program for the multiplication of square matrices. Help him write the code.



// Note: Square matrices mean the number of rows equals the number of columns in the given matrix.

// Input format :
// The first line of input consists of the matrix size M.

// The next M lines of input consist of the M elements in each line separated by space representing the first matrix.

// After being separated by a new line, the next M lines of input consist of the M elements in each line separated by space representing the second matrix.

// Output format :
// The output should display the product of the two matrices in a M x M format.

// Each element of the matrix should be separated by a tab space (\t).



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ M ≤ 10

// 0 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 3
// 2 3 2
// 3 2 3
// 3 3 3

// 4 5 6
// 2 3 1
// 1 2 3
// Output 1 :
// The product of the two matrices is:
// 16	23	21	
// 19	27	29	
// 21	30	30	
// Input 2 :
// 2
// 2 2
// 2 3

// 5 6
// 7 8
// Output 2 :
// The product of the two matrices is:
// 24	28	
// 31	36	


// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr1[n][n],arr2[n][n],arr3[n][n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr2[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr3[i][j]=0;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                arr3[i][j]+=arr1[i][k]*arr2[k][j];
                // cout<<arr3[i][j]<<" ";
            }
        }
    }
    cout<<"The product of the two matrices is:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
}





// You are in the process of creating a program to ascertain whether a provided string qualifies as a palindrome. A palindrome refers to a string that reads the same both forward and backward. To achieve this, you are tasked to implement a function named isPalindrome that utilizes string objects. 

// Input format :
// The input consists of a string of alphanumeric characters (lowercase and uppercase characters, digits, and special characters)

// Output format :
// The output displays a single line containing one of the following messages:



// "The string is a palindrome" if the input string is a palindrome.

// "The string is not a palindrome" if the input string is not a palindrome.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ string length ≤ 100 characters

// The input string is case-sensitive.

// Sample test cases :
// Input 1 :
// madam
// Output 1 :
// The string is a palindrome
// Input 2 :
// 123@321
// Output 2 :
// The string is a palindrome
// Input 3 :
// Highlevel
// Output 3 :
// The string is not a palindrome
// Input 4 :
// Radar
// Output 4 :
// The string is not a palindro


// You are using GCC
#include<iostream>
#include<string>
using namespace std;
int isPalindrome(string str){
    int n=str.length();
    int mid=n/2;
    int i =0;
    int cnt=0;
    while(i<mid-1){
        if(str[i]==str[n-1]){
            cnt++;
            // cout<<str[i]<<" "<<str[n-1]<<" "<<endl;
            i++;
            n--;
        }else{
            break;
        }
        
    }
    // cout<<mid;
    // cout<<cnt;
    if(cnt==mid-1){
        cout<<"The string is a palindrome"<<endl;
    }else{
        cout<<"The string is not a palindrome"<<endl;
    }
}
int main(){
    string str;
    cin>>str;
    isPalindrome(str);
    
}





// Maran is working on a programming problem involving an array of objects. He has created a class named ArrayElement to store integer values in an array. Now he needs to find the number of times a specific integer appears in the given array.



// Write a program that helps Maran achieve this task. The program should create an array of objects of class ArrayElement, where each object contains an integer value. It should then find and display how many times a particular integer, srch_num, appears in the array.

// Input format :
// The first line contains an integer n, representing the number of elements in the array.

// The second line contains n space-separated integers, each representing the values stored in the array.

// The third line contains an integer, srch_num (the number to be searched).

// Output format :
// The output should display the following format:

// If srch_num is found in the array, output the message "The number srch_num appears ctr times," where ctr is the count of occurrences.

// If srch_num is not found in the array, output the message "The number srch_num is not found in the array".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 15

// 1 ≤ array elements ≤ 1000

// 1 ≤ srch_num ≤ 1000

// Sample test cases :
// Input 1 :
// 13
// 1 5 2 1 2 5 5 5 5 3 5 7 5
// 5
// Output 1 :
// The number 5 appears 7 times
// Input 2 :
// 13
// 1 5 2 1 2 5 5 5 5 3 5 7 5
// 15
// Output 2 :
// The number 15 is not found i


// You are using GCC
#include<iostream>
using namespace std;
class ArrayElement{
    public:
    int x;
    
};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cnt++;
        }
    }
    if(cnt>=1){
    cout<<"The number "<<key<<" appears "<<cnt<<" times"<<endl;
    }else{
        cout<<"The number "<<key<<" is not found in the array"<<endl;
    }
}



// Manu wants to add up the money given by his mother and father. Both of them gave the money in rupees and paisa. Help him write a program to print the total rupees by creating class Money with two attributes rupee(int) and paisa(int). 



// In the main method initialize the values for the data members and print their sum. Bind the data members and member functions inside the class.

// Input format :
// The input consists of two amounts in each line.

// For each amount, the input consists of rupee and paisa as integers separated by a space.

// Output format :
// The output prints the total sum of the two amounts in the format: "X:Y" where X and Y are the calculated amount.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 0 ≤ rupee ≤ 105

// 0 ≤ paisa ≤ 99

// Sample test cases :
// Input 1 :
// 50 50
// 10 50
// Output 1 :
// 61.0
// Input 2 :
// 200 45
// 800 20
// Output 2 :
// 1000.65
// Input 3 :
// 0 90
// 1 10
// Output 3 :
// 2.0


// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void resultt(float result){
   float frac=result-static_cast<int>(result);
   float shift=frac*pow(10,2);
   int fi=result;
   cout<<fi<<".";
   cout<<fixed<<setprecision(0)<<shift;
}

int main(){
    int x1,x2;
    int y1,y2;
    cin>>x1>>x2;
    cin>>y1>>y2;
    float x=x1*100+x2;
    float y=y1*100+y2;
    float sum=x+y;
    float result=sum/100;
    resultt(result);
    // cout<<fixed<<setprecision(1)<<result;
}




// You are tasked with designing a simple airline reservation system for a small airline company. The system should allow the airline to manage and provide information about their flight destinations and the number of flights available to each destination.



// You need to implement a class named Airline with the following functions:

// void initialize(): Initializes the airline's system with no destinations and no flights.
// void addDestination (int, int): Adds a new destination and the number of flights available to that destination. The system can store up to 100 destinations.
// int checkFlights (int): Checks and returns the number of available flights to a specific destination. If the destination is not found, it returns -1.
// Input format :
// The first input consists of an integer n, representing the number of destinations the airline wants to add.

// The next n lines consist of two space-separated integers for each destination: destination code and number of flights available.

// The last input consists of an integer search for destination Q.

// Output format :
// The output displays the following one of the format:

// If the search destination is found in the system, it prints the number of available flights to that destination.

// If the search destination is not found in the system, it prints "Destination not found."



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 50

// Sample test cases :
// Input 1 :
// 3
// 101 5
// 102 3
// 103 7
// 102
// Output 1 :
// 3
// Input 2 :
// 4
// 201 8
// 202 4
// 203 6
// 204 2
// 205
// Output 2 :
// Destination not found



// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void initialize(){
    cout<<"svfd";
    
}
void addDestination(int x,int y){
    int z;
    int p;
    
}

void checkFlights(int y){
    int z;

}
int main(){
    int n;
    cin>>n;
    int sum=-1;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i]>>arr2[i];
    }
    int des;
    cin>>des;
    int cnt=-1;
    for(int i=0;i<n;i++){
        // sum=-1;
        for(int j=0;j<n;j++){
            if(arr1[i]==des){
                cnt=i;
            }
        }
        
    
    if(cnt==i){
        cout<<arr2[i];
         sum=0;
    }
}   if(sum!=0){
        cout<<"Destination not found"<<endl;
    }
    
}
