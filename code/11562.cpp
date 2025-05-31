#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int n,m;
int d[255][255];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fill(d[i],d[i]+n+1,INF);
    }
    while(m--){
        int a,b,c; cin>>a>>b>>c;
        d[a][b]=0;
        d[b][a]=0;
        if(c==0){   //단방향
            d[b][a]=1;  //존재하는 길을 뒤짚은 횟수가 필요
        }
    }
    for(int i=1;i<=n;i++){
        d[i][i]=0;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }  
    }

    int k; cin>>k;
    while(k--){
        int a,b; cin>>a>>b;
        cout<<d[a][b]<<"\n";
    }
    return 0;
}