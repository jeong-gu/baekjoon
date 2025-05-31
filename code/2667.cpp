#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char maze[26][26];
bool visited[26][26];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<int> vec;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>maze[i][j];
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]&&maze[i][j]=='1'){
                cnt++;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j]=true;
                int homecnt=0;
                while(!q.empty()){
                    pair<int,int> tmp=q.front();
                    q.pop();
                    homecnt++;
                    for(int k=0;k<4;k++){
                        int nx=tmp.X+dx[k];
                        int ny=tmp.Y+dy[k];
                        if(nx<0||nx>=n||ny<0||ny>=n) continue;
                        if(maze[nx][ny]=='0'||visited[nx][ny]) continue;
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
                vec.push_back(homecnt);
            }
            visited[i][j]=true;
        }
    }
    sort(vec.begin(),vec.end());
    cout<<cnt<<"\n";
    for(auto i:vec){
        cout<<i<<"\n";
    }
    return 0;
}