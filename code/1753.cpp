#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int v,e,k;
int d[20005];
vector<pair<int,int>> edge[20005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>v>>e;
    cin>>k;
    
    fill(d,d+1+v,INF);
    d[k]=0;

    for(int i=0;i<e;i++){
        int u,v,w; 
        cin>>u>>v>>w;
        edge[u].push_back({w,v});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({d[k],k});
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        if(d[cur.second]!=cur.first) continue;
        for(auto nxt:edge[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first)continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }
    for(int i=1;i<=v;i++){
        if(d[i]==INF) cout<<"INF\n";
        else cout<<d[i]<<"\n";
    }

    return 0;
}