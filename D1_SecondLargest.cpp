// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

// Note: The second largest element should not be equal to the largest element.

// Examples:

// Input: arr[] = [12, 35, 1, 10, 34, 1]
// Output: 34
// Explanation: The largest element of the array is 35 and the second largest element is 34.
// Input: arr[] = [10, 5, 10]
// Output: 5
// Explanation: The largest element of the array is 10 and the second largest element is 5.
// Input: arr[] = [10, 10, 10]
// Output: -1
// Explanation: The largest element of the array is 10 and the second largest element does not exist.
// Constraints:
// 2 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105

// You are using GCC
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    
    int getSecondLargest(vector<int> &arr){
        int max=arr[0];
        int sMax;
        for(int i=0;i<arr.size();i++){
            if(max<arr[i]){
                sMax=max;
                max=arr[i];
            }
        }
        if(max==sMax){
            return -1;
        }else{
            return sMax;
        }
       
    }
};
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
      vector<int> arr;
      string input;
      getline(cin,input);
      stringstream ss(input);
      int number;
      while(ss>>number){
          arr.push_back(number);
      }
      Solution ob;
    // vector<int> arr={12,14,11,16,17,9,19};
      int ans=ob.getSecondLargest(arr);
      cout<<ans<<endl;
      cout<<"~"<<endl;
    }
}