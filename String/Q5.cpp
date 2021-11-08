// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// } Driver Code Ends

char flip(char ch){
    return (ch=='0') ? '1':'0';
}
int flipWithStartingCh(string str, char expected){
    int count=0;
    int n=str.length();
    for(int i=0;i<n;i++){
        if(str[i]!=expected){
            count++;
        }
        expected=flip(expected);
    }
    return count;
}
int minFlips (string S)
{
    // your code here
    /*
    000 =>  010
    001 =>  101
    100 =>
    110 =>
    111 =>
    */
    return min(flipWithStartingCh(S,'0'),flipWithStartingCh(S,'1'));
}
