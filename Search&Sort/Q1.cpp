// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    bool isMajority(int a[], int size,int cand){
        int count=0;
        for(int i=0;i<size;i++){
            if(a[i]==cand){
                count++;
            }
        }
        if(count>size/2){
            return true;
        }
        return false;
    }
    int findCandidate(int a[], int size){
        int maj_index=0;
        int count=1;
        for(int i=1;i<size;i++){
            if(a[maj_index]==a[i]){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                maj_index=i;
                count=1;
            }
        }
        return a[maj_index];
    }
    int majorityElement(int a[], int size)
    {
        // your code here
        bool flag=false;
        int cand=0;
        cand=findCandidate(a,size);
        flag=isMajority(a,size,cand);
        if(flag){
            return cand;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
