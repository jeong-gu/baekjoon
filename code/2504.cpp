#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    stack<char> stk;
    int weight=1;
    int result=0;
    char prev=' ';
    bool flag=false;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            weight*=2;
            stk.push(str[i]);
        }
        else if(str[i]=='['){
            weight*=3;
            stk.push(str[i]);
        }
        else if(str[i]==')'){
            if(stk.empty()||stk.top()!='('){
                flag=true;
                break;
            }
            if(prev=='('){
                result+=weight;
                weight/=2;
                stk.pop();
            }
            else{
                weight/=2;
                stk.pop();
            }
        }
        else if(str[i]==']'){
            if(stk.empty()||stk.top()!='['){
                flag=true;
                break;
            }
            if(prev=='['){
                result+=weight;
                weight/=3;
                stk.pop();
            }
            else{
                weight/=3;
                stk.pop();
            }
        }
        prev=str[i];
    }
    if(flag||!stk.empty()) cout<<"0";
    else cout<<result;

    return 0;
}