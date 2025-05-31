#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> stk;
    string str;
    cin>>str;
    char prev=' ';
    int cnt=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            stk.push(str[i]);
        }
        else if(str[i]==')'){
            if(prev=='('){
                stk.pop();
                cnt+=stk.size();
            }
            else{
                stk.pop();
                cnt+=1;
            }
        }
        prev=str[i];
    }
    cout<<cnt;
    return 0;
}