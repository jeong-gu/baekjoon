#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int dp[100001];
int func(int root,int parent){
    if(dp[root]) return dp[root]; 
    int rt=0;
    for(auto x: adj[root]){
        if(parent==x) continue;
        rt+=func(x,root);
    }
    dp[root]=rt+1;
    return dp[root];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,r,q; cin>>n>>r>>q;
    n--;
    while(n--){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    func(r,-1);
    while(q--){
        int y; cin>>y;
        cout<<dp[y]<<"\n";
    }

    return 0;
}