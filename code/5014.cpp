#include <bits/stdc++.h>
using namespace std;
int f,s,g,u,d;
int maze[1000001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>f>>s>>g>>u>>d;
    fill(maze,maze+f+1,-1);
    queue<int> q;
    q.push(s);
    maze[s]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto i:{u,-d}){
            int xx=x+i;
            if(xx<=0||xx>f) continue;
            if(maze[xx]==-1){
                q.push(xx);
                maze[xx]=maze[x]+1;
            }
        }
    }
    if(maze[g]==-1){
        cout<<"use the stairs";
    }
    else{
        cout<<maze[g];
    }
    return 0;
}