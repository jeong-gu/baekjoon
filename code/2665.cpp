#include <bits/stdc++.h>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int mz[51][51];
int dis[51][51];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string str; cin>>str;
        for(int j=0;j<str.size();j++){
            mz[i][j]=str[j]-'0';
        }
    }
    for(int i=0;i<51;i++) fill(dis[i],dis[i]+51,0x3f3f3f3f);
    queue<pair<int,int>> q;
    q.push({0,0});
    dis[0][0]=0;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n) continue;
            if(mz[nx][ny]==1){
                if(dis[nx][ny]>dis[cur.first][cur.second]){
                    dis[nx][ny]=dis[cur.first][cur.second];
                    q.push({nx,ny});
                }
            }
            else{
                if(dis[nx][ny]>dis[cur.first][cur.second]){
                    dis[nx][ny]=dis[cur.first][cur.second]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout<<dis[n-1][n-1];
    return 0;
}