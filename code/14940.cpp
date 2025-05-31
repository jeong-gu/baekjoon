#include <bits/stdc++.h>
using namespace std;
int INF=500000;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int maze[1001][1001];
int goal[1001][1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    int stx,sty;
    for(int i=0;i<1001;i++)
    for(int j=0;j<1001;j++)
        goal[i][j]=INF;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
            if(maze[i][j]==0){
                goal[i][j]=0;
            }
            else if(maze[i][j]==2){
                stx=i; sty=j;
            }
        }
    }
    queue<pair<int,int>> q;
    goal[stx][sty]=0;
    q.push({stx,sty});
    while(!q.empty()){
        int x,y;
        tie(x,y)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(goal[nx][ny]!=INF) continue;
            q.push({nx,ny});
            goal[nx][ny]=goal[x][y]+1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(goal[i][j]==INF){
                cout<<"-1 ";
            }
            else 
                cout<<goal[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}


