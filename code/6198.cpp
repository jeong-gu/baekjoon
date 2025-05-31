#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    stack<int> stk;
    int idx0; cin>>idx0;
    stk.push(idx0);
    long long result=0;
    for(int i=0;i<n-1;i++){
        int tmp;
        cin>>tmp;
        while(!stk.empty()&&stk.top()<=tmp){
            stk.pop();
        }
        result+=stk.size();
        stk.push(tmp);
    }
    cout<<result;
    return 0;
}

