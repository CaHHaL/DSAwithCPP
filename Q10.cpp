//exception handling
// Write a program to validate a password based on certain criteria. 



// The program should check the length of the password must be at least 6 characters and ensure it contains at least one digit (0-9). If the password does not meet these criteria, an appropriate error message should be displayed.



// Implement the program using exception-handling mechanisms.

// Input format :
// The first line of input consists of a string representing the username.

// The second line consists of a string representing the password.

// Output format :
// If the password meets all the criteria, output "Password is correct"

// If the password is less than 6 characters long, output "Password must be at least 6 characters long."

// If the password does not contain at least one digit, output "Password must have at least One digit (0-9)"

// For all the exception that occurs, print "Caught by exception, invalid password format!", in the last line.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The maximum length of the username is 50 characters.

// The maximum length of the password is 20 characters.

// Sample test cases :
// Input 1 :
// Santo
// san@12
// Output 1 :
// Password is correct
// Input 2 :
// Sona
// 1234
// Output 2 :
// Password must be at least 6 characters long.
// Caught by exception, invalid password format!
// Input 3 :
// HarishS
// harish
// Output 3 :
// Password must have at least One digit (0-9)
// Caught by exception, invalid password format!
// Input 4 :
// Ramesh
// @ramu
// Output 4 :
// Password must be at least 6 characters long.
// Caught by exception, invalid password format!

// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    string username;
    cin>>username;
    string pass;
    cin>>pass;
    int cnt=0;
    int bnt=1;
    try{
        if(pass.length()<6){
        bnt=0;
        throw 1;
        
    }
    for(int i=0;i<pass.length();i++){
        if(pass[i]>='0' && pass[i]<='9'){
            cnt=1;
            break;
        }
    }
    if(cnt==0 && pass.length()>=6){
        throw 'a'; 
    }
    
    }
    catch(int x){
        cout<<"Password must be at least 6 characters long."<<endl;
        cout<<"Caught by exception, invalid password format!"<<endl;
    }
    catch(char& a){
        cout<<"Password must have at least One digit (0-9)"<<endl;
        
        cout<<"Caught by exception, invalid password format!"<<endl;
    }
    if(cnt==1 && bnt==1){
        cout<<"Password is correct"<<endl;
    }
    
}






// Mitha, a dedicated customer support executive, is faced with the challenge of validating mobile numbers provided by customers. To enhance the efficiency of this process, she envisions a program that not only takes a customer's mobile number as input but also ensures it is a valid 10-digit number containing only digits (0–9). 



// Mitha desires a robust solution that utilizes exception handling to provide customers with clear feedback regarding the validity of their entered mobile numbers.

// Input format :
// The input consists of a single line containing a string representing the customer's mobile number.

// Output format :
// The output prints in the following format:



// The first line of output displays the given mobile number.

// If the mobile number contains characters other than digits (0–9), the program should output "Invalid input".

// If the mobile number has less than or greater than 10 digits, the program should output: "The mobile number should have 10 digits".

// If the mobile number has exactly 10 digits and contains only digits, the program should output: "The entered mobile number is valid".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 0 <= Mobile number <= 9

// The mobile number should have exactly 10 digits.

// Sample test cases :
// Input 1 :
// 9856984256
// Output 1 :
// 9856984256
// The entered mobile number is valid
// Input 2 :
// 85658542
// Output 2 :
// 85658542
// The mobile number should have 10 digits
// Input 3 :
// abdc987654
// Output 3 :
// Invalid input


// You are using GCC
#include<bits/stdc++.h>
using namespace std;

int main(){
    string num;
    cin>>num;

    try{
         for(int i = 0 ; i<num.length();i++){
            if(num[i] < '0' || num[i] >'9'){
                throw 1;
            }
        }
        if(num.length() != 10){
            throw 'x';
        }
        throw 123.678f;
        
    }catch(int x){
        cout<<"Invalid input"<<endl;
    }catch(const char& x){
        cout<<num<<endl;
        cout<<"The mobile number should have 10 digits"<<endl;
    }catch(float x){
        cout<<num<<endl;
        cout<<"The entered mobile number is valid"<<endl;
    }
}