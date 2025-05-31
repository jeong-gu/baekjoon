#include <bits/stdc++.h>
using namespace std;
char star[2200][2200];
void func(int x,int y,int z){
    if(z==1){
        star[x][y]='*';
        return;
    }
    int n=z/3;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
        if(i==1&&j==1) continue;
        func(x+n*i,y+n*j,n);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    for(int i=0;i<2200;i++){
        fill(star[i],star[i]+2200,' ');
    }
    int n; cin>>n;
    func(0,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<star[i][j];
        }
        cout<<"\n";
    }
    return 0;
}