#include <bits/stdc++.h>
using namespace std;
int arr[501][501];
bool visited[501][501];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    queue<pair<int,int>> q;
    int cnt=0,max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&arr[i][j]==1){
                int area=0;
                cnt++;
                visited[i][j]=true;
                q.push({i,j});
                area++;
                while(!q.empty()){
                    int curx=q.front().first;
                    int cury=q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++){
                        int nx=curx+dx[i];
                        int ny=cury+dy[i];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(visited[nx][ny]||arr[nx][ny]!=1) continue;
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                        area++;               
                    }
                }
                if(max<area){
                    max=area;
                }
            }
        }
    }
    std::cout<<cnt<<"\n"<<max;
    return 0;
}