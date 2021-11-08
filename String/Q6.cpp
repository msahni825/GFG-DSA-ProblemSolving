// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        string result="";
        vector<int> freq;
        unordered_map<string,int> mp;
        unordered_map<string,int>::iterator it;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(it=mp.begin();it!=mp.end();it++){
            freq.push_back(it->second);
        }
        sort(freq.begin(),freq.end());
        reverse(freq.begin(),freq.end());
        int val=freq[1];
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second==val){
                result=it->first;
                break;
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
