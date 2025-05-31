#include <bits/stdc++.h>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int mz[1001][1001];
int dis[1001][1001][11];
struct adj{
    int a,b,c,x;
};
int n,m,k;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c; cin>>c;
            mz[i][j]=c-'0';
        }
    }
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            for(int k=0;k<11;k++){
                dis[i][j][k]=-1;
            }
        }
    }
    queue<adj> q;
    q.push({1,1,0,0});
    dis[1][1][0]=1;
    int day=true;
    
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            auto cur=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=cur.a+dx[i];
                int ny=cur.b+dy[i];
                if(nx<1||ny<1||nx>n||ny>m) continue;
                if(mz[nx][ny]==1){
                    if(cur.c+1>k||dis[nx][ny][cur.c+1]!=-1) continue;
                    if(day){
                        dis[nx][ny][cur.c+1]=dis[cur.a][cur.b][cur.c]+1+cur.x;
                        q.push({nx,ny,cur.c+1,0});
                    }
                    else{
                        q.push({cur.a,cur.b,cur.c,cur.x+1});
                    }
                }
                else{
                    if(cur.c>k||dis[nx][ny][cur.c]!=-1) continue;
                    dis[nx][ny][cur.c]=dis[cur.a][cur.b][cur.c]+1+cur.x;
                    q.push({nx,ny,cur.c,0});
                }
            }
        }
        day=!day;
    }
    int mn=987654321;
    for(int i=0;i<=k;i++){
        if(dis[n][m][i]==-1)continue;
        mn=min(mn,dis[n][m][i]);
    }
    if(mn==987654321) cout<<"-1";
    else cout<<mn;
    return 0;
}