#include <bits/stdc++.h>
using namespace std;
int main(){
  while(1){ 
    string str;
    getline(cin,str);
    if(str==".") break;
    stack<char> stk;
    bool flag=false;
    for(int i=0;i<str.length();i++){
      if(str[i]=='('||str[i]=='['){
        stk.push(str[i]);
      }
      else if(str[i]==')'){
        if(!stk.empty()&&stk.top()=='('){
          stk.pop();
        }
        else{
          flag=true;
          break;
        }
      }
      else if(str[i]==']'){
        if(!stk.empty()&&stk.top()=='['){
          stk.pop();
        }
        else{
          flag=true;
          break;
        }
      }
    }
    if(!flag&&stk.empty())cout<<"yes\n";
    else cout<<"no\n";
  }


  return 0;
}