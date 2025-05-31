#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int n,e;
vector<pair<int,int>> adj[805];
int func(int st,int en){
    int d[805];
    fill(d,d+n+1,INF);
    d[st]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({st,d[st]});
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        if(d[cur.first]!=cur.second) continue;
        for(auto nxt:adj[cur.first]){
            if(d[nxt.first]<=d[cur.first]+nxt.second) continue;
            d[nxt.first]=d[cur.first]+nxt.second;
            pq.push({nxt.first,d[nxt.first]});
        }
    }
    return d[en];

    //1번 -> 2번 + 2번 -> 3번 + 3번-> n번
    //1번 -> 3번 + 3번 -> 2번 + 2번 -> n번  
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>e;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int v1,v2; cin>>v1>>v2;
    int x1=func(1,v1);
    int x2=func(v1,v2);
    int x3=func(v2,n);
    int result=0;
    if(x1!=INF&&x2!=INF&&x3!=INF){
        result=x1+x2+x3;
    }
    swap(v1,v2);
    x1=func(1,v1);
    x2=func(v1,v2);
    x3=func(v2,n);
    if(x1!=INF&&x2!=INF&&x3!=INF){
        result=min(result,x1+x2+x3);
    }

    if(result!=0){
        cout<<result;
    }
    else{
        cout<<-1;
    }


    return 0;
}