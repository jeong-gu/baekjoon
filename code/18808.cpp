#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int board[45][45];
int sticker[4][45][45];
bool overlap(int dir,int i,int j,int nn,int mm){
        for(int x=0;x<nn;x++){
        for(int y=0;y<mm;y++){
            if(sticker[dir][x][y]){
                if(board[i+x][j+y]) return true;
            }
        }
    }
    return false;

}
bool oper(int dir,int i,int j,int nn,int mm){
    if(i+nn>n||j+mm>m) return false;
    if(!overlap(dir,i,j,nn,mm)){
        for(int x=0;x<nn;x++){
            for(int y=0;y<mm;y++){
                board[i+x][j+y]+=sticker[dir][x][y];
            }
        }
        return true;
    }
    return false;
}
void rotate(int dir,int mm,int nn){
    queue<int> q;
    for(int j=0;j<mm;j++){
        for(int i=nn-1;i>=0;i--){
            if(sticker[dir-1][i][j]==1)
                q.push(1);
            else
                q.push(0);
        }
    }
    for(int i=0;i<mm;i++){
        for(int j=0;j<nn;j++){
            sticker[dir][i][j]=q.front();
            q.pop();
        }
    }
}
void func(){
    int nn,mm; cin>>nn>>mm;
    for(int i=0;i<nn;i++){
        for(int j=0;j<mm;j++){
            cin>>sticker[0][i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(oper(0,i,j,nn,mm)){
                return;
            }
        }
    }
    rotate(1,mm,nn);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(oper(1,i,j,mm,nn)){
                return;
            }
        }
    }
    rotate(2,nn,mm);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(oper(2,i,j,nn,mm)){
                return;
            }
        }
    }
    rotate(3,mm,nn);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(oper(3,i,j,mm,nn)){
                return;
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    while(k--){
        func();
        for(int i=0;i<4;i++){
            for(int j=0;j<45;j++){
                for(int k=0;k<45;k++){
                    sticker[i][j][k]=0;
                }
            }
        }
    }
    int area=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]!=0){
                area++;
            }
        }
    }
    cout<<area;
    return 0;
}