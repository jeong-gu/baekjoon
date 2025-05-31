#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll INF=0x7f7f7f7f7f7f;
int n,m,k;
vector<pair<int,int>> adj[100001];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
ll d[100001];
void func(){
    while(!pq.empty()){
        int u,v;
        ll w,dw;
        tie(w,u)=pq.top();
        pq.pop();
        if(d[u]!=w)continue;
        for(auto nxt: adj[u]){
            tie(dw,v)=nxt;
            dw+=w;
            if(dw>=d[v]) continue;
            d[v]=dw;
            pq.push({dw,v});
        }
        
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    fill(d,d+n+1,INF);
    while(m--){
        ll a,b,c; cin>>a>>b>>c;
        adj[b].push_back({c,a});
    }
    while(k--){
        int city;
        cin>>city;
        d[city]=0;
        pq.push({d[city],city});
    }
    func();

    int cidx=max_element(d+1,d+n+1)-d;//인덱스
    cout<<cidx<<"\n"<<d[cidx];
    return 0;
}