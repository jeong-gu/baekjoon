#include <bits/stdc++.h>
using namespace std;
int n, maxheight=0;
int maze[101][101];
int result=1;
bool visited[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void bfs(int height){
    int rresult=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(maze[i][j]<=height||visited[i][j]) continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            rresult++;
            while(!q.empty()){
                auto tmp=q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int nx=tmp.first+dx[k]; 
                    int ny=tmp.second+dy[k];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(maze[nx][ny]<=height||visited[nx][ny]) continue;
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    result=(result<rresult)?rresult:result;
    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            visited[i][j]=false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
            if(maxheight<maze[i][j])maxheight=maze[i][j];
        }
    for(int i=1;i<=maxheight;i++){
        bfs(i);
    }
    cout<<result;
    return 0;
}