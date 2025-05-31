#include <bits/stdc++.h>    
using namespace std;
int dp[10001][5];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int X;
    int a[4];
    vector<int> vec={1,5,10,25};
    cin>>X;
    for(int i=0;i<4;i++){
        cin>>a[i];
    }
    for(int i=0;i<10001;i++){
        for(int j=0;j<5;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<5;i++){
        dp[0][i]=0;
    }


    for(int i=1;i<=X;i++){
        for(int j=0;j<4;j++){
            if(dp[i][j]==-1) dp[i][j]=0;
            if(i-vec[j]<0) continue;
            if(dp[i-vec[j]][4]>dp[i][4]){
                if(a[j]>=dp[i-vec[j]][j]+1){
                    for(int k=0;k<5;k++){
                        dp[i][k]=dp[i-vec[j]][k];
                    }
                    dp[i][4]++;
                    dp[i][j]++;
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        cout<<dp[X][i]<<" ";
    }
    return 0;
}