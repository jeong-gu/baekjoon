#include <bits/stdc++.h>
using namespace std;
char maze[64][64];
bool check(int x,int y,int n){
    int tmp=maze[x][y];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        if(maze[x+i][y+j]!=tmp)
            return false;
    return true;
}
void func(int x,int y,int z){
    if(check(x,y,z)){
        cout<<maze[x][y];
        return;
    }
    cout<<"(";
    int n=z/2;
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
        func(x+n*i,y+n*j,n);
    cout<<")";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>maze[i][j];
    func(0,0,n);
    return 0;
}