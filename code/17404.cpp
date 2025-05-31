#include <bits/stdc++.h>
using namespace std;
int dp[3][1001];
int rgb[3][1001];
int ans=987654321;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>rgb[0][i]>>rgb[1][i]>>rgb[2][i];
    }
    for(int k=0;k<3;k++){
        for(int i=0;i<3;i++){
            if(i==k){
                dp[k][1]=rgb[k][1];
            }
            else{
                dp[i][1]=987654321;
            }
        }
        for(int i=2;i<=n;i++){
            dp[0][i]=rgb[0][i]+min(dp[1][i-1],dp[2][i-1]);
            dp[1][i]=rgb[1][i]+min(dp[0][i-1],dp[2][i-1]);
            dp[2][i]=rgb[2][i]+min(dp[1][i-1],dp[0][i-1]);
        }
        
        for(int i=0;i<3;i++){
            if(i==k) continue;
            ans=min(ans,dp[i][n]);
        }
    }
    cout<<ans;

    return 0;
}