#include <bits/stdc++.h>
using namespace std;

pair<int,int> d[5001];
int dp[10001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        int n; double m;
        cin>>n>>m;
        int target=int(m*100+0.5);
        if(n==0 && m==0.00) break;
        for(int i=0;i<n;i++){
            int tmp1; double tmp2; cin>>tmp1>>tmp2;
            int tmp3=int(tmp2*100+0.5);
            d[i]={tmp1,tmp3};
        }
        fill(dp,dp+10001,0);
        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                if(i-d[j].second<0) continue;
                dp[i]=max(dp[i],dp[i-d[j].second]+d[j].first);
            }
        }
        int ans=0;
        for(int i=0;i<=target;i++){
            ans=max(ans,dp[i]);
        }
        cout<<ans<<"\n";
    }

    return 0;
}