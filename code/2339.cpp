#include <bits/stdc++.h>
using namespace std;
int n;
int a[21][21];
int solve(int x1,int x2,int y1,int y2,bool iswidth){
    bool isbul=false,isbo=false;
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            if(a[i][j]==1) {isbul=true;}
            else if(a[i][j]==2) {isbo=true;}
        }
    }
    if(!isbul) return -1;
    if(!isbo) return 0;

    int result=0;
    bool cancut=false;
    if(iswidth){
        for(int i=x1+1;i<x2;i++){
            bool isbulrow=false;
            for(int j=y1;j<y2;j++){
                if(a[i][j]==1){
                    isbulrow=true;
                    break;
                }
            }
            if(isbulrow){
                int top=solve(x1,i,y1,y2,!iswidth);
                int bottom=solve(i,x2,y1,y2,!iswidth);
                if(top!=-1&&bottom!=-1){
                    result+=top+bottom+1;
                    cancut=true;
                }
            }
        }
    }
    
    
    else{
        for(int j=y1+1;j<y2;j++){
            bool isbulcol=false;
            for(int i=x1;i<x2;i++){
                if(a[i][j]==1){
                    isbulcol=true;
                    break;
                }
            }
            if(isbulcol){
                int l=solve(x1,x2,y1,j,!iswidth);
                int r=solve(x1,x2,j,y2,!iswidth);
                if(l!=-1&&r!=-1){
                    result+=l+r+1;
                    cancut=true;
                }
            }
        }
    }
    return cancut?result:-1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>a[i][j];
    cout<<solve(0,n,0,n,true);

    return 0;
}