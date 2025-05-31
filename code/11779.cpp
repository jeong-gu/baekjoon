#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int v,e,k;
int d[1005];
int pre[1005];
vector<pair<int,int>> edge[1005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>v>>e;
    
    fill(d,d+1+v,INF);

    for(int i=0;i<e;i++){
        int u,v,w; 
        cin>>u>>v>>w;
        edge[u].push_back({w,v});
    }
    int k,s; cin>>k>>s;
    d[k]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({d[k],k});
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        if(d[cur.second]!=cur.first) continue;
        for(auto nxt:edge[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first)continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            pre[nxt.second]=cur.second;
            pq.push({d[nxt.second],nxt.second});
        }
    }
    cout<<d[s]<<"\n";
    stack<int> stk;
    int tmp=s;
    while(tmp!=k){
        stk.push(tmp);
        tmp=pre[tmp];
    }
    stk.push(k);
    cout<<stk.size()<<"\n";
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}