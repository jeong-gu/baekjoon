#include <bits/stdc++.h>
using namespace std;
char maze[6][6];
bool isused[26];
bool board[6][6];
bool visited[6][6];
int dasomcnt;
int result;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool adj(){
    queue<pair<int,int>> q;
    int cnt=0;
    for(int i=0;i<25;i++){
        if(isused[i]){
            board[i/5][i%5]=true;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(board[i][j]&&!visited[i][j]){
                q.push({i,j});
                cnt++;
                if(maze[i][j]=='S') dasomcnt++;
                visited[i][j]=true;
                while(!q.empty()){
                    auto x=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int xx=x.first+dx[k];
                        int yy=x.second+dy[k];
                        if(xx<0||xx>=5||yy<0||yy>=5) continue;
                        if(!board[xx][yy]||visited[xx][yy]) continue;
                        q.push({xx,yy});
                        visited[xx][yy]=true;
                        if(maze[xx][yy]=='S') dasomcnt++;
                    }
                }
            }
        }
    }
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            visited[i][j]=false;
            board[i][j]=false;
        }
    if(cnt==1)return true;
    else return false;
}
void func(int x,int pos){
    if(x==7){
        dasomcnt=0;
        if(adj()){
            if(dasomcnt>=4){
                result++;
            }
        }
        return;
    }
    for(int i=pos;i<25;i++){
        if(!isused[i]){
            isused[i]=true;
            func(x+1,i);
            isused[i]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
        cin>>maze[i][j];
    }
    func(0,0);
    cout<<result;
    return 0;
}