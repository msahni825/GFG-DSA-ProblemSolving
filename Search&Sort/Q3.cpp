// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        vector<vector<int> > result;
        int n=arr.size();
        if(n<4){
            return result;
        }
        int sum=0;
        for(int i=0;i<n-3;i++){
            if(i>0 && arr[i-1]==arr[i]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && arr[j-1]==arr[j]){
                    continue;
                }
                int low=j+1;
                int high=n-1;
                while(low<=high){
                    int left=low;
                    int right=high;
                    sum=arr[i]+arr[low]+arr[high];
                    if(sum==k){
                        vector<int> vec;
                        vec.push_back(arr[i]);
                        vec.push_back(arr[j]);
                        vec.push_back(arr[left]);
                        vec.push_back(arr[right]);
                        result.push_back(vec);
                        while(low<high && arr[left]==arr[low]){
                            low++;
                        }
                        while(low<high && arr[high]==arr[right]){
                            high--;
                        }
                    }
                    else if(sum<k){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
