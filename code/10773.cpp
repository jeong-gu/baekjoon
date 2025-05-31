#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
int main(){
    int k,c;
    cin>>k;
    while(k--){
        cin>>c;
        if(c==0){
            stk.pop();
        }
        else{
            stk.push(c);
        }
    }
    int sum=0;
    while(!stk.empty()){
        sum+=stk.top();
        stk.pop();
    }
    cout<<sum;
    return 0;
}