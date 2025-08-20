#include <bits/stdc++.h>
using namespace std;

int pre[31][31];
int post[31][31];
int visited[31][31];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>pre[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>post[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool swt=true;
            //visited 초기화
            for(int k=0;k<n;k++){
                for(int l=0;l<m;l++){
                    visited[k][l]=0;
                }
            }
            
            int val=pre[i][j];
            int postval=post[i][j];
            queue<pair<int,int>> q;
            q.push({i,j});
            visited[i][j]=postval;
            while(!q.empty()){
                auto cur=q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int nxtX=cur.first+dx[k];
                    int nxtY=cur.second+dy[k];
                    if(nxtX<0||nxtY<0||nxtX>=n||nxtY>=m||visited[nxtX][nxtY]) continue;
                    if(pre[nxtX][nxtY]!=val) continue;
                    visited[nxtX][nxtY]=postval;
                    q.push({nxtX,nxtY});
                    if(post[nxtX][nxtY]!=postval){
                        swt=false;
                        break;
                    }
                }
            }

            for(int k=0;k<n;k++){
                for(int l=0;l<m;l++){
                    if(!visited[k][l]) visited[k][l]=pre[k][l];
                }
            }

            if(swt){
                bool sswt=true;
                for(int k=0;k<n;k++){
                    for(int l=0;l<m;l++){
                        if(visited[k][l]!=post[k][l]) sswt=false;
                    }
                }
                if(!sswt) continue;
                cout<<"YES";
                return 0;
            }
        }
    }

    cout<<"NO";
    return 0;
}