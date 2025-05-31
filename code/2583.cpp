#include <bits/stdc++.h>
using namespace std;
bool visited[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m,n,k;
    queue<pair<int,int>> q;
    cin>>m>>n>>k;
    while(k--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=0;i<y2-y1;i++){
            for(int j=0;j<x2-x1;j++){
                visited[y1+i][x1+j]=true;                
            }
        }
    }
    int cnt=0;
    vector<int> vec;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]) continue;
            int area=0;
            cnt++;
            q.push({i,j});
            visited[i][j]=true;
            while(!q.empty()){
                int curx=q.front().first;
                int cury=q.front().second;
                q.pop();
                area++;
                for(int x=0;x<4;x++){
                    int xx=curx+dx[x];
                    int yy=cury+dy[x];
                    if(xx<0||xx>=m||yy<0||yy>=n) continue;
                    if(visited[xx][yy]) continue;
                    q.push({xx,yy});
                    visited[xx][yy]=true;

                }
            }
            vec.push_back(area);
        }
    }
    sort(vec.begin(),vec.end());
    cout<<cnt<<"\n";
    for(auto i:vec){
        cout<<i<<" ";
    }
    return 0;
}