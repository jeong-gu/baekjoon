#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[11][100001];
vector<pair<ll,ll>> vec[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k,s,t; cin>>n>>m>>k>>s>>t;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,-1});
    }

    for(int i=0;i<11;i++){
        fill(dp[i],dp[i]+100001,-0x3f3f3f3f3f);
    }
    for(int i=0;i<=k;i++){
        dp[i][t]=0;
        for(int st=n;st>0;st--){
            for(auto x:vec[st]){
                if(x.second!=-1){
                    if(dp[i][x.first]==-0x3f3f3f3f3f) continue;
                    dp[i][st]=max(dp[i][st],dp[i][x.first]+x.second);
                }
                else{
                    if(i==0) continue;
                    dp[i][st]=max(dp[i][st],dp[i-1][x.first]);
                }
            }
        }
    }
    ll ans=dp[k][s];

    if(ans==-0x3f3f3f3f3f){
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}