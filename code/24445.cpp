#include <bits/stdc++.h>
using namespace std;
int visited[100001];
vector<int> adj[100001];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,r; cin>>n>>m>>r;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<100001;i++){
        sort(adj[i].begin(),adj[i].end(),cmp);
    }
    int order=0;
    queue<int> q;
    q.push(r);
    visited[r]=++order;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto nxt:adj[cur]){
            if(visited[nxt]) continue;
            visited[nxt]=++order;
            q.push(nxt);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<visited[i]<<"\n";
    }

    return 0;
}