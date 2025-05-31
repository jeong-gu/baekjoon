#include <bits/stdc++.h>    
using namespace std;
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int arr[501][501];
int mx=-1;
bool visited[501][501];
void dfs(int x, int y, int cnt, int sum) {
    if (cnt == 4) {
        mx = max(mx, sum);
        return;
    }

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny])
            continue;

        visited[nx][ny] = true;
        dfs(nx, ny, cnt + 1, sum + arr[nx][ny]);
        visited[nx][ny] = false;
    }
}

int func(int a,int b){
    int tmp[4];
    int result=0;
    for(int i=0;i<4;i++){
        int tmp=arr[a][b];
        for(int j=0;j<3;j++){
            int nx=dx[(i+j)%4];
            int ny=dy[(i+j)%4];
            if(a+nx<0||b+ny<0||a+nx>=n||b+ny>=m) break;
            tmp+=arr[a+nx][b+ny];
        }
        result=max(result,tmp);
    }
    return result;
}
void bfs(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int result=func(i,j);
            mx=max(mx,result);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>arr[i][j];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=true;
            dfs(i,j,1,arr[i][j]);
            visited[i][j]=false;
        }
    }

    bfs();
    cout<<mx;
    

    return 0;
}