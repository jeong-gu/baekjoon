#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll d[16];
ll dp[16][1<<16];
ll func(ll now,ll bm){
    if(bm==(1<<n)-1) return 1;
    if(dp[now][bm]!=-1) return dp[now][bm];

    dp[now][bm]=0;
    for(ll i=0;i<n;i++){
        if(!(bm&(1<<i))&&abs(d[i]-d[now])>k){
            dp[now][bm]+=func(i,bm|(1<<i));
        }
    }
    return dp[now][bm];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        cin>>d[i];
    }
    fill(&dp[0][0],&dp[n-1][1<<n],-1);
    ll ret=0;
    for(ll i=0;i<n;i++){
        ret+=func(i,(1<<i));
    }
    cout<<ret;
    
    return 0;
}