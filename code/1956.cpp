#include <bits/stdc++.h>
using namespace std;
int INF=0x3f3f3f3f;
int v,e;
int d[401][401];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>v>>e;
    for(int i=1;i<=v;i++){
        fill(d[i],d[i]+v+1,INF);
    }
    while(e--){
        int a,b,c; cin>>a>>b>>c;
        d[a][b]=c;
    }
    for(int i=1;i<=v;i++){
        d[i][i]=0;
    }
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    int mn=INF;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(i==j)continue;
            mn=min(mn,d[i][j]+d[j][i]);
        }
    }
    if(mn==INF){
        cout<<-1;
    }
    else{
        cout<<mn;
    }
    return 0;
}