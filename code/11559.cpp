#include <bits/stdc++.h>
using namespace std;
char arr[6][12];
bool visited[6][12];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int boom=0;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin>>arr[j][i];
        }
    }
    bool end=false;
    while(!end){
        end=true;
        for(int i=0;i<6;i++){
            for(int j=0;j<12;j++){
                if(arr[i][j]!='.'&&!visited[i][j]){
                    queue<pair<int,int>> q;
                    vector<pair<int,int>> vec;
                    q.push({i,j});
                    vec.push_back({i,j});
                    visited[i][j]=true;
                    int cnt=1;
                    char key=arr[i][j];
                    while(!q.empty()){
                        auto tmp=q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nx=tmp.first+dx[k];
                            int ny=tmp.second+dy[k];
                            if(nx<0||nx>=6||ny<0||ny>=12) continue;
                            if(visited[nx][ny]||arr[nx][ny]!=key) continue;
                            q.push({nx,ny});
                            visited[nx][ny]=true;
                            cnt++;
                            vec.push_back({nx,ny});
                        }
                    }
                    if(cnt>=4){
                        for(auto i:vec){
                            arr[i.first][i.second]='.';
                            end=false;
                        }
                    }            
                }
            }
        }
        for(int i=0;i<6;i++){
            for(int j=0;j<12;j++){
                visited[i][j]=false;
            }
        }
        stack<char> stk;
        for(int i=0;i<6;i++){
            for(int j=0;j<12;j++){
                if(arr[i][j]!='.'){
                    stk.push(arr[i][j]);
                    arr[i][j]='.';
                }
            }
            int j=12-1;
            while(!stk.empty()){
                arr[i][j]=stk.top();
                stk.pop();
                j--;
            }
        }
        if(!end) boom++;
        
    }
    cout<<boom;

    return 0;
}