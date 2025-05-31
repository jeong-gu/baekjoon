#include <bits/stdc++.h>
using namespace std;
int maze[129][129];
int blue=0,white=0;
bool check(int x,int y,int n){
    int tmp=maze[x][y];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        if(maze[x+i][y+j]!=tmp)
            return false;
    return true;
}
void func(int x,int y,int n){
    if(check(x,y,n)){
        if(maze[x][y]==1) blue++;
        else white++;
        return;
    }
    int m=n/2;
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
        func(x+m*i,y+m*j,m);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>maze[i][j];
    func(0,0,n);    
    cout<<white<<"\n"<<blue;
    return 0;
}