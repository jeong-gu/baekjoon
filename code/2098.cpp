#include <bits/stdc++.h>    
using namespace std;
int n;
int adj[16][16];
int d[16][1<<16];
int func(int now,int state){
    if(d[now][state]!=-1) return d[now][state];

    if(state==(1<<n)-1){
        if (adj[now][0]) {
            d[now][state] = adj[now][0];
        }
        else {
            d[now][state] = 987654321;
        }
        return d[now][state];
    }

    d[now][state]=987654321;
    for(int i=0;i<n;i++){
        if(adj[now][i]==0) continue;
        if(state&(1<<i)) continue;

        d[now][state]=min(d[now][state],func(i,state|(1<<i))+adj[now][i]);
    }
    return d[now][state];   
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    for(int i=0;i<16;i++){
        fill(d[i],d[i]+(1<<16),-1);
    }
    cout<<func(0,1);

    return 0;
}