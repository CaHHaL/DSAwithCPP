

// Guna wants to write a program that counts the number of occurrences of a specific character in a given string. 



// He decided to create a class called Occurrence to handle this task. In the class, a string and character are its private attributes. Initialize the variables using a member function. Define a member function countOccurrence() to count the number of times the character occurs in the string.



// Note: This is a sample question asked in a Capgemini interview.

// Input format :
// The first line of input consists of a string, str.

// The second line of input consists of a single character, ch, which represents the character to be counted for its occurrence in the string.

// Output format :
// The output displays a single integer representing the count of occurrences of the character ch in the given input string str.

// Code constraints :
// Use the small-case alphabet (a–z), numbers, and special characters.

// Sample test cases :
// Input 1 :
// utter
// t
// Output 1 :
// 2
// Input 2 :
// 453vgft
// 5
// Output 2 :
// 1
// Input 3 :
// ftf@fdfd@
// @
// Output 3 :
// 2

// You are using GCC
#include<iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    char ch;
    cin>>ch;
    int count=0;
    for(char cha: str){
        if(cha==ch){
            count++;
        }
    }
    cout<<count;
    
}



// Cooper is learning about shapes and geometry. He wants to create a program that helps him calculate the area and perimeter of a rectangle. Implement a Rectangle class that takes the length and breadth as inputs and has attributes to store these values. In the main function, create an object of the Rectangle class, set the length and breadth, and then print out the area and perimeter of the rectangle.

// Input format :
// The input consists of two space-separated integers representing the length and breadth of a rectangle.

// Output format :
// The first line of output prints "Area: " followed by the area of the rectangle.

// The second line of output prints "Perimeter: " followed by the perimeter of the rectangle.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ length, breadth ≤ 100

// Sample test cases :
// Input 1 :
// 10 20
// Output 1 :
// Area: 200
// Perimeter: 60
// Input 2 :
// 14 18
// Output 2 :
// Area: 252
// Perimeter: 64

#include<iostream>
using namespace std;
class Rectangle{
    public:
    int l;
    int b;
    int perimeter(int l,int b);
    int area(int l,int b);
};
int Rectangle::perimeter(int l,int b){
    return (l+b)+(l+b);
    // return 2(l+b);
}
int Rectangle::area(int l,int b){
    return l*b;
}
int main(){
    Rectangle obj;
   int l;
   int b;
   cin>>l>>b;
   int perimeter=obj.perimeter(l,b);
   int area=obj.area(l,b);
   
    
    cout<<"Area: "<<area<<endl;
    cout<<"Perimeter: "<<perimeter;
}