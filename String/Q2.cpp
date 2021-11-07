// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method 

    Expected Time Complexity: O(N*N) | N^2
    Expected Auxiliary Space: O(N*N) | N^2

    */
    long long int countPS(string str)
    {
       //Your code here
       const unsigned int M = 1000000007;
       long long int n=str.size();
       long long int dp[n+1][n+1];
       memset(dp,0,sizeof(dp));
       
       for(int i=0;i<n;i++){
           dp[i][i]=1;
       }
       for(int i=2;i<=n;i++){
           for(int j=0;j<=n-i;j++){
               int k=i+j-1;
               if(str[j]==str[k]){
                   dp[j][k]=dp[j][k-1]+dp[j+1][k]+1;
               }
               else{
                   dp[j][k]=dp[j][k-1]+dp[j+1][k]-dp[j+1][k-1];
               }
           }
       }
       return dp[0][n-1]%M;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends
