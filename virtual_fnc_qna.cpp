// Santhosh is designing a painting application that allows users to select a color and paint on a digital canvas. Your task is to enhance the painting application by adding a user-friendly menu that prompts the user to choose a color to paint on the canvas. The user can input either 'R' or 'r' to select the Red color or 'B' or 'b' to select the Blue color.



// Write a program to implement runtime polymorphism. The program should define a base class "Color" with a virtual function "paint" and two derived classes "RedPaint" and "BluePaint" that override the "paint()" function to paint with the respective colors.



// The program should use runtime polymorphism to create either a "RedPaint" or "BluePaint" object based on user input and call the "paint()" function to paint with the chosen color.



// Note: This kind of question will help in clearing Cocubes recruitment.

// Input format :
// The input consists of a single character representing the color to paint, where "R" or "r" represents the red color and "B" or "b" represents a blue color.

// Output format :
// The program should output the message "I'm Painting with Red Color." if the user inputs 'R' or 'r', or "I'm Painting with Blue Color."

// If the user inputs "B" or "b". If the user inputs any other character, the program should output "Invalid choice!" and terminate.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The user's input must be a single character.

// The user can only enter 'R', 'r', 'B', or 'b' to select a color.

// Any other character will be considered an invalid choice.

// Sample test cases :
// Input 1 :
// R
// Output 1 :
// I'm Painting with Red color.
// Input 2 :
// B
// Output 2 :
// I'm Painting with Blue color.
// Input 3 :
// M
// Output 3 :
// Invalid choice!








// You are using GCC
#include<iostream>
using namespace std;
class Color{
    public:
    void virtual paint(){
        cout<<"I am painting"<<endl;
    }
};
class RedPaint: public Color{
   public:
   void paint(){
       cout<<"I'm Painting with Red color."<<endl;
   }
};
class BluePaint: public Color{
    public:
    void paint(){
        cout<<"I'm Painting with Blue color."<<endl;
    }
};
int main(){
    Color *ptr;
    char c;
    cin>>c;
    if(c=='R' || c=='r'){
       ptr=new RedPaint;
       ptr->paint();
    }else if(c=='b' || c=='B'){
         ptr=new BluePaint;
       ptr->paint();
    }else{
        cout<<"Invalid choice!"<<endl;
    }   
}



// Rohith is designing a program that consists of a base class Expression with a pure virtual function evaluate().



// There are two derived classes PowerAB and PowerBA representing expressions of the form ab and ba respectively, where a and b are real numbers. The program takes the values of a and b as input and calculates and displays the power results for both types of expressions.



// Note: Use the pow function from the math library to calculate the power value.

// Input format :
// The input consists of two space-separated double values a and b.

// Output format :
// The first line of output prints the value of ab as a double-value, rounded off to two decimal places.

// The second line prints the value of ba as a double-value, rounded off to two decimal places.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1.0 ≤ a, b ≤ 10.0

// Sample test cases :
// Input 1 :
// 4.5 2.0
// Output 1 :
// 20.25
// 22.63
// Input 2 :
// 1.1 1.1
// Output 2 :
// 1.11
// 1.11






// You are using GCC
#include<bits/stdc++.h>
using namespace std;
class Expression{
  public:
  virtual void evaluate(double a,double b)=0;
};
class PowerAB: public Expression{
    public:
    void evaluate(double a,double b){
        cout<<fixed<<setprecision(2)<<pow(a,b)<<endl;
    }
};
class PowerBA:public Expression{
    public:
    void evaluate(double a,double b){
    cout<<fixed<<setprecision(2)<<pow(b,a)<<endl;    
    }
};
int main(){
    Expression *ptr;
    double a,b;
    cin>>a>>b;
    ptr=new PowerAB;
    ptr->evaluate(a,b);
    ptr=new PowerBA;
    ptr->evaluate(a,b);
}
