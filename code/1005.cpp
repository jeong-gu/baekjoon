#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int dis[1001];
vector<int> adj[1001];
int pre[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        fill(arr,arr+1001,0);
        fill(dis,dis+1001,0);
        fill(pre,pre+1001,0);
        for(int i=0;i<1001;i++){
            fill(adj[i].begin(),adj[i].end(),0);
        }
        int n,k; cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=0;i<k;i++){
            int x,y; cin>>x>>y;
            adj[x].push_back(y);
            pre[y]++;
        }
        int w; cin>>w;
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(pre[i]==0){
                q.push(i);
                dis[i]=arr[i];
            }
        }
        while(!q.empty()){
            int cur=q.front(); q.pop();
            if(cur==w) {cout<<dis[cur]<<"\n"; break;}
            for(auto nxt:adj[cur]){
                dis[nxt]=max(dis[nxt],dis[cur]+arr[nxt]);
                if(--pre[nxt]==0){
                    q.push(nxt);
                }
            }
        }
    }
    return 0;
}