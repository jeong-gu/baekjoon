#include <bits/stdc++.h>
using namespace std;
vector<int> vec[51];
int dp[51];
int func(int x){
    if(dp[x]) {
        return dp[x];
    }
    if(vec[x].empty()) return 0;

    vector<int> tmp;
    for(auto k: vec[x]){
        tmp.push_back(func(k));
    }
    sort(tmp.begin(),tmp.end(),greater<int>());
    int rt=0;
    int r=1;
    for(auto f: tmp){
        rt=max(rt,f+r);
        r++;
    }
    dp[x]=rt;
    return rt;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(x==-1) continue;
        vec[x].push_back(i);
    }
    cout<<func(0);

    return 0;
}