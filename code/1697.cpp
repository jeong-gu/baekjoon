#include <bits/stdc++.h>
using namespace std;
int dis[100001];
int dx[2]={1,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dis,dis+100001,-1);
    int n,k;
    cin>>n>>k;
    queue<int> q;
    q.push(n);
    dis[n]=0;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        if(tmp==k){
                cout<<dis[tmp];
                return 0;
            }
        for(int i=0;i<2;i++){
            int tmpx=tmp+dx[i];
            
            if(tmpx<0||tmpx>100000) continue;
            if(!(dis[tmpx]==-1)) continue;
            q.push(tmpx);
            dis[tmpx]=dis[tmp]+1;
        }
        int tmpx=tmp*2;
        if(tmpx<0||tmpx>100000) continue;
        if(!(dis[tmpx]==-1)) continue;
        q.push(tmpx);
        dis[tmpx]=dis[tmp]+1;
    }
    return 0;
}