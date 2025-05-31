#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200001];
int pre[200001];
int visited[200001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b;
        adj[i].push_back(a);
        adj[i].push_back(b);
        pre[a]++;
        pre[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(pre[i]<2){
            q.push(i);
            visited[i]=true;
        }
    }
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(auto nxt:adj[cur]){
            if(visited[nxt]) continue;
            if(--pre[nxt]<2){
                q.push(nxt);
                visited[nxt]=true;
            }
        }
    }
    int cnt=0;
    vector<int> res;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            res.push_back(i);
        }
    }   
    cout<<cnt<<"\n";
    for(auto x:res) cout<<x<<" ";
    return 0;
}