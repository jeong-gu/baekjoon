#include <bits/stdc++.h>
using namespace std;
int pre[501];
int arr[501];
vector<int> adj[501];
int dis[501];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        int a;
        while(1){
            cin>>a;
            if(a==-1) break;
            adj[a].push_back(i);
            pre[i]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(pre[i]==0){
            q.push(i);
            dis[i]=arr[i];
        }
    }
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(auto nxt:adj[cur]){
            dis[nxt]=max(dis[nxt],dis[cur]);
            if(--pre[nxt]==0){
                q.push(nxt);
                dis[nxt]+=arr[nxt];
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<"\n";
    }
    return 0;
}