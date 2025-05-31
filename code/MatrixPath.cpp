#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int d[105][105];
int x[105][105];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>d[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        fill(x[i],x[i]+m,INF);
    }
    x[1][1]=d[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1)continue;
            else if(i==1){
                x[i][j]=d[i][j]+x[i][j-1];
            }
            else if(j==1){
                x[i][j]=d[i][j]+x[i-1][j];
            }
            else{
                x[i][j]=d[i][j]+min(x[i-1][j],x[i][j-1]);
            }
        }
    }
    cout<<x[n][m];

    return 0;
}