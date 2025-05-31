#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int n,m,x;
int d[1005];
int normal[1005];
int reversed[1005];
vector<pair<int,int>> adj[1005];
vector<pair<int,int>> adjRev[1005];
void func(int st,vector<pair<int,int>> vec[]){
    fill(d,d+n+1,INF);
    d[st]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({st,d[st]});
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        if(d[cur.first]!=cur.second) continue;
        for(auto nxt:vec[cur.first]){
            if(d[nxt.first]<=d[cur.first]+nxt.second) continue;
            d[nxt.first]=d[cur.first]+nxt.second;
            pq.push({nxt.first,d[nxt.first]});
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>x;
    while(m--){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adjRev[b].push_back({a,c});
    }
    func(x,adj);
    for(int i=1;i<=n;i++){
        normal[i]=d[i];
    }
    func(x,adjRev);
    for(int i=1;i<=n;i++){
        reversed[i]=d[i];
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,normal[i]+reversed[i]);
    }
    cout<<mx;

    return 0;
}