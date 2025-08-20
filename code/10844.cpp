#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][10];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    dp[1][0]=0;
    for(int i=1;i<10;i++){
        dp[1][i]=1;
    }
    
    for(int i=1;i<=n;i++){
        dp[i+1][0]=dp[i][1];
        dp[i+1][9]=dp[i][8];
        for(int j=1;j<9;j++){
            dp[i+1][j]=(dp[i][j-1]+dp[i][j+1])%1000000000;
        }
    }

    int res=0;
    for(int i=0;i<10;i++){
        res=(res+dp[n][i])%1000000000;
    }
    cout<<res;

    return 0;
}