#include <bits/stdc++.h>
using namespace std;
int stairs[310];
int dp[3][310];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stairs[i];
    }
    dp[1][1]=stairs[1];
    for(int i=2;i<=n;i++){
        dp[1][i]=max(dp[1][i-2],dp[2][i-2])+stairs[i];
        dp[2][i]=dp[1][i-1]+stairs[i];
    }
    cout<<max(dp[1][n],dp[2][n]);
    return 0;
}