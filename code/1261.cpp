#include <bits/stdc++.h>    
using namespace std;
int INF=0x3f3f3f3f;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int m,n;
char arr[101][101];
int brokenCnt[101][101];
bool visited[101][101];
//백트래킹
void func(int x,int y,int cnt){
    if(cnt>brokenCnt[n-1][m-1]) return;
    if(cnt>=brokenCnt[x][y])return;
    
    brokenCnt[x][y]=cnt;
    if(x==n-1&&y==m-1) return;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=m) continue;
        if(visited[nx][ny])continue;
        visited[nx][ny]=true;
        func(nx,ny,cnt+arr[nx][ny]);
        visited[nx][ny]=false;
    }
}
int main(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char tmp;
            cin>>tmp;
            arr[i][j]=tmp-'0';
            brokenCnt[i][j]=INF;
        }
    }
    visited[0][0]=1;
    func(0,0,0);

    cout<<brokenCnt[n-1][m-1];
    return 0;

}