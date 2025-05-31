#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dis[1001][1001][2];
char maze[1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
int bfs(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dis[i][j][0]=dis[i][j][1]=-1;
    dis[0][0][0]=dis[0][0][1]=1;
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    while(!q.empty()){
        int x,y,swt;
        tie(x,y,swt)=q.front();
        if(x==n-1&&y==m-1)return dis[x][y][swt];
        q.pop();
        int nextdis=dis[x][y][swt]+1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i]; int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(maze[nx][ny]=='0'&&dis[nx][ny][swt]==-1){
                dis[nx][ny][swt]=nextdis;
                q.push({nx,ny,swt});
            }
            if(!swt&&maze[nx][ny]=='1'&&dis[nx][ny][swt]==-1){
                dis[nx][ny][1]=nextdis;
                q.push({nx,ny,1});
            }
        }
    }
    return -1;

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>maze[i][j];
    cout<<bfs();
    return 0;
}