#include <bits/stdc++.h>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
int mz[1001][1001];
int visited[1001][1001];
void func(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=1;
    int cnt=1;
    vector<pair<int,int>> vec;
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=cur.first+dx[k];
            int ny=cur.second+dy[k];
            if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny]) continue;
            if(mz[nx][ny]){
                vec.push_back({nx,ny});
            }
            else{
                q.push({nx,ny});
                cnt++;
            }
            visited[nx][ny]=1;
        }
    }
    for(auto x: vec){
        mz[x.first][x.second]+=cnt;
        visited[x.first][x.second]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin>>c;
            mz[i][j]=c-'0';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mz[i][j]==0&&!visited[i][j]){
                func(i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mz[i][j]%10;
        }
        cout<<"\n";
    }


    return 0;
}