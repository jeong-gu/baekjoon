#include <bits/stdc++.h>    
using namespace std;
int INF=0x3f3f3f3f;
int n,m,st,en;
bool path[10002];
int d[502];

vector<tuple<int,int,int>> adj[502];
vector<tuple<int,int,int>> rev_adj[502];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

queue<int> q;

void setup(){
    for(int i=0;i<n;i++){
        adj[i].clear();
        rev_adj[i].clear();
    }
    fill(path,path+m,0);
    cin>>st>>en;
    for(int i=0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({cost,v,i});
        rev_adj[v].push_back({cost,u,i});
    }
}

void func(){
    fill(d,d+n,INF);
    d[st]=0;
    pq.push({st,d[st]});
    while(!pq.empty()){
        auto [cur,cost]=pq.top();
        pq.pop();
        if(d[cur]!=cost) continue;
        for(auto [ncost,nxt,id]:adj[cur]){
            if(path[id]==1) continue;
            if(d[nxt]<=ncost+cost) continue;
            d[nxt]=ncost+cost;
            pq.push({nxt,ncost+cost});
        }
    }
}

void deletePath(){
    q.push(en);
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        for(auto [ncost,pre,id]:rev_adj[cur]){
            if(path[id]==1) continue;
            int dist=d[cur]-ncost;
            if(d[pre]!=dist) continue;
            q.push(pre);
            path[id]=1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        cin>>n>>m;
        if(n==0&&m==0) break;
        setup();
        func();
        deletePath();
        func();

        if(d[en]==INF) cout<<"-1\n";
        else cout<<d[en]<<"\n";
    }

    return 0;
}