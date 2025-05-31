#include <bits/stdc++.h>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char mp[1001][1001];
int visitedFire[1001][1001];
int visitedHuman[1001][1001];
void bfs(queue<pair<int,int>> q,int visited[1001][1001],int w,int h){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=h||ny>=w||visited[nx][ny]!=INT_MAX||mp[nx][ny]=='#') continue;
            visited[nx][ny]=visited[x][y]+1;
            q.push({nx,ny});
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int w,h; cin>>w>>h;
        queue<pair<int,int>> qHuman;
        queue<pair<int,int>> qFire;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                visitedFire[i][j]=INT_MAX;
                visitedHuman[i][j]=INT_MAX;
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>mp[i][j];
                if(mp[i][j]=='@'){
                    qHuman.push({i,j});
                    visitedHuman[i][j]=1;
                }
                if(mp[i][j]=='*'){
                    qFire.push({i,j});
                    visitedFire[i][j]=1;
                }
            }
        }
        bfs(qFire,visitedFire,w,h);
        bfs(qHuman,visitedHuman,w,h);
        int mn=INT_MAX;
        for(int i=0;i<w;i++){
            if(visitedHuman[0][i]!=INT_MAX&&visitedHuman[0][i]<visitedFire[0][i]&&mn>visitedHuman[0][i]){
                mn=visitedHuman[0][i];
            }
            if(visitedHuman[h-1][i]!=INT_MAX&&visitedHuman[h-1][i]<visitedFire[h-1][i]&&mn>visitedHuman[h-1][i]){
                mn=visitedHuman[h-1][i];
            }
        }
        for(int i=0;i<h;i++){
            if(visitedHuman[i][0]!=INT_MAX&&visitedHuman[i][0]<visitedFire[i][0]&&mn>visitedHuman[i][0]){
                mn=visitedHuman[i][0];
            }
            if(visitedHuman[i][w-1]!=INT_MAX&&visitedHuman[i][w-1]<visitedFire[i][w-1]&&mn>visitedHuman[i][w-1]){
                mn=visitedHuman[i][w-1];
            }
        }
        if(mn==INT_MAX){
            cout<<"IMPOSSIBLE\n";
        }
        else{
            cout<<mn<<"\n";
        }
    }


    return 0;
}