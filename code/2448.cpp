#include <bits/stdc++.h>
using namespace std;
char star[3072][7000];
void func(int x,int y,int z){
    if(z==3){
        for(int i=0;i<5;i++)
            star[x][y+i]='*';
        for(auto i:{1,3}){
            star[x+1][y+i]='*';
        }
        star[x+2][y+2]='*';
        return;
    }
    func(x,y,z/2);
    func(x,y+z,z/2);
    func(x+z/2,y+z/2,z/2);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++)
        fill(star[i],star[i]+7000,' ');
    func(0,0,n);
    for(int i=n-1;i>=0;i--){
        for(int j=2*n-2;j>=0;j--){
            cout<<star[i][j];
        }
        cout<<"\n";
    }
    return 0;
}