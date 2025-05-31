#include <bits/stdc++.h>
using namespace std;
int maze[2200][2200];
int cnt[3];
bool check(int x,int y,int n){
    int first=maze[x][y];
    for(int i=x;i<x+n;i++)
    for(int j=y;j<y+n;j++)
        if(maze[i][j]!=first) return false;
    return true;
}
void func(int x,int y,int n){
    if(check(x,y,n)){
        cnt[maze[x][y]+1]++;
        return;
    }
    int nxt=n/3;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        func(x+nxt*i,y+nxt*j,nxt);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>maze[i][j];
    func(0,0,n);
    for(int i=0;i<3;i++)cout<< cnt[i]<<"\n";
    return 0;
}