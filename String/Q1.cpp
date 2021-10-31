// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}
//} Driver Code Ends
int countRev (string s)
{
    // your code here
    int count=0;
    int result=0;
    stack<char> stk;
    
    if(s.size()%2){
        return -1;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='}' && !stk.empty()){
            if(stk.top()=='{'){
                stk.pop();
            }
            else{
                stk.push(s[i]);   
            }
        }
        else{
            stk.push(s[i]);
        }
    }
    int stack_sz=stk.size();
    
    while(!stk.empty() && stk.top()=='{'){
        stk.pop();
        count++;
    }
    result=(stack_sz/2+(count%2));
    return result;
    
}
