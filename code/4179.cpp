#include <bits/stdc++.h>
using namespace std;
char maze[1001][1001];
int dis[1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<pair<int,int>> fire;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r,c;
    queue<pair<int,int>> q;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        fill(dis[i],dis[i]+c,-1);
    }
    int JR,JC,fireR,fireC;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='J'){
                JR=i;
                JC=j;
            }
            else if(maze[i][j]=='F'){
                fire.push_back({i,j});
            }
        }
    }
                    
    for(auto i:fire){
        q.push({i.first,i.second});
    }
    dis[JR][JC]=1;
    q.push({JR,JC});
    while(!q.empty()){
        pair<int,int> tmp=q.front();
        if((maze[tmp.first][tmp.second]=='.'
        ||maze[tmp.first][tmp.second]=='J')
        &&(tmp.first==r-1
            ||tmp.first==0
            ||tmp.second==0
            ||tmp.second==c-1)){
                cout<<dis[tmp.first][tmp.second];
                return 0;
            }
        q.pop();
        for(int i=0;i<4;i++){
            int nr=tmp.first+dx[i];
            int nc=tmp.second+dy[i];
            if(nr<0||nr>=r||nc<0||nc>=c) continue;
            if(dis[nr][nc]>=0||maze[nr][nc]!='.') continue;
            if(maze[tmp.first][tmp.second]=='F'){
                maze[nr][nc]='F';
            }
            dis[nr][nc]=dis[tmp.first][tmp.second]+1;
            q.push({nr,nc});
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}