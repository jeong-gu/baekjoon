#include <bits/stdc++.h>   
using namespace std;
int INF=0x3f3f3f3f;
int n,m,r;
int d[101][101];
int item[101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
        cin>>item[i];
    }
    for(int i=1;i<=n;i++){
        fill(d[i],d[i]+n+1,INF);
    }
    for(int i=1;i<=r;i++){
        int a,b,c; cin>>a>>b>>c;
        d[a][b]=c;
        d[b][a]=c;
    }
    for(int i=1;i<=n;i++){
        d[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        int result=0;
        for(int j=1;j<=n;j++){
            if(d[i][j]<=m){
                result+=item[j];
            }
        }
        mx=max(mx,result);
    }
    cout<<mx;
    return 0;
}