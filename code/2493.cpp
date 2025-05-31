#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>> stk;
vector<int> result;
int main(){
    int n;
    cin>>n;
    stk.push({100000001,0});
    for(int i=1;i<=n;i++){
        int height;
        cin>>height;
        while(stk.top().first<height){
            stk.pop();
        }
        result.push_back(stk.top().second);
        stk.push({height,i});
    }    
    for(auto i:result){
        cout<<i<<" ";
    }

    return 0;
}