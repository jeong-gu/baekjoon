#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int dp[10001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        fill(dp,dp+10001,INF);
        vector<pair<int,int>> vec[10001];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n,d,c; cin>>n>>d>>c;
        for(int i=0;i<d;i++){
            int a,b,s; cin>>a>>b>>s;
            vec[b].push_back({s,a});
        }        
        dp[c]=0;
        pq.push({dp[c],c});
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            if(dp[cur.second]!=cur.first) continue;
            for(auto nxt:vec[cur.second]){
                if(dp[nxt.second]<=dp[cur.second]+nxt.first) continue;
                dp[nxt.second]=dp[cur.second]+nxt.first;
                pq.push({dp[nxt.second],nxt.second});
            }
        }
        int cnt=0,tm=0;
        for(int i=1;i<=n;i++){
            if(dp[i]!=INF){
                cnt++;
                tm=max(tm,dp[i]);
            }
        }
        cout<<cnt<<" "<<tm<<"\n";
    }


    return 0;
}