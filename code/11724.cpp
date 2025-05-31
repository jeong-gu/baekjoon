#include <bits/stdc++.h>
using namespace std;
bool visited[1001];
bool arr[1001][1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    while(m--){
        int x,y; cin>>x>>y;
        arr[x][y]=true;        
        arr[y][x]=true;
    }
    int cnt=0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int tmp=q.front();
                q.pop();
                for(int j=1;j<=n;j++){
                    if(!arr[tmp][j]||visited[j]) continue;
                    q.push(j);
                    visited[j]=true;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}