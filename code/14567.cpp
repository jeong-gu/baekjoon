#include <bits/stdc++.h>
using namespace std;
int pre[1001];
vector<int> adj[1001];
int d[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        pre[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(pre[i]==0){
            q.push(i);
            d[i]=1;
        }
    }
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(auto nxt:adj[cur]){
            if(--pre[nxt]==0){
                q.push(nxt);
                d[nxt]=d[cur]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}