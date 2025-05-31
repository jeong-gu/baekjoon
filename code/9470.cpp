#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int k,m,p; cin>>k>>m>>p;
        vector<int> adj[1001];
        int pre[1001];
        int dis[1001];
        int swt[1001];
        fill(pre,pre+1001,0);
        fill(dis,dis+1001,0);
        fill(swt,swt+1001,0);
        for(int i=0;i<1001;i++){    
            adj[i].resize(0);
        }
        for(int i=1;i<=p;i++){
            int a,b; cin>>a>>b;
            pre[b]++;
            adj[a].push_back(b);
        }
        queue<int> q;
        for(int i=1;i<=m;i++){
            if(pre[i]==0){
                q.push(i);
                dis[i]=1;
            }
        }
        while(!q.empty()){
            int cur=q.front(); q.pop();
            for(auto nxt:adj[cur]){
                if(dis[nxt]<dis[cur]){
                    swt[nxt]=1;
                    dis[nxt]=dis[cur];
                }
                else if(dis[nxt]==dis[cur]){
                    swt[nxt]++;
                }
                if(--pre[nxt]==0){
                    q.push(nxt);
                    if(swt[nxt]>=2) dis[nxt]+=1;
                }
            }
        }
        cout<<k<<" ";
        int ans=0;
        for(int i=1;i<=m;i++){
            ans=max(ans,dis[i]);
        }
        cout<<ans<<"\n";
    }


    return 0;
}