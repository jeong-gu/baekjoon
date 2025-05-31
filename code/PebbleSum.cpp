#include <bits/stdc++.h>
using namespace std;
int board[5][105];
int w[105][5];
int d[105][5];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            cin>>board[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++){
            if(j==4){
                w[i][j]=board[1][i]+board[3][i];
            }
            else{
                w[i][j]=board[j][i];
            }
        }
    }
    for(int i=1;i<=4;i++){
        d[1][i]=w[1][i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=4;j++){
            if(j==1){
                d[i][j]=max(d[i-1][2],d[i-1][3])+w[i][j];
            }
            else if(j==2){
                d[i][j]=max({d[i-1][1],d[i-1][3],d[i-1][4]})+w[i][j];
            }
            else if(j==3){
                d[i][j]=max(d[i-1][1],d[i-1][2])+w[i][j];
            }
            else if(j==4){
                d[i][j]=d[i-1][2]+w[i][j];
            }
        }
    }
    cout<<max({d[n][1],d[n][2],d[n][3],d[n][4]});
    return 0;
}