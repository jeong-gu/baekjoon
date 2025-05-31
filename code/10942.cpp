#include <bits/stdc++.h>
using namespace std;
int arr[2001];
int dp[2001][2001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=1;
        if(i==n) break;
        if(arr[i]==arr[i+1]){
            dp[i][i+1]=1;
        }
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+2;j<=n;j++){
            if(arr[i]==arr[j]&&dp[i+1][j-1]) dp[i][j]=1;
        }
    }
    int m; cin>>m;
    while(m--){
        int s,e; cin>>s>>e;
        cout<<dp[s][e]<<"\n";
    }
    return 0;
}