#include <bits/stdc++.h>
using namespace std;
int n,m;
int maze[8][8];
int result=128;
int tvcnt;
int dx[4]={1,0,-1,0};   //1: {i} //2: {i,-i} //3: {i,i+1}
int dy[4]={0,1,0,-1};   // 4:except i // 5: all dir
bool isused[8][8];
void func(int x,int pos){
    if(x==tvcnt){
        int unseen=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j]==0){
                    unseen++;
                }
            }
        }
        result=(result>unseen)?unseen:result;
        return;
    }
    for (int p = pos; p < n * m; p++) {
        int i = p / m;
        int j = p % m;
        if(!isused[i][j]){
            if(maze[i][j]==1){
                for(int k=0;k<4;k++){
                    int xx=1;
                    while(1){
                        if((i+xx*dx[k])<0||(i+xx*dx[k])>=n||(j+xx*dy[k])<0||(j+xx*dy[k])>=m) break;
                        int tmp=maze[i+xx*dx[k]][j+xx*dy[k]];
                        if(tmp==6) break;
                        if(tmp==0||tmp>=10){ 
                            maze[i+xx*dx[k]][j+xx*dy[k]]+=10;
                        }
                        xx++;
                    }
                    isused[i][j]=true;
                    func(x+1,(m*i)+j+1);
                    isused[i][j]=false;
                    xx=1;
                    while(1){
                        if((i+xx*dx[k])<0||(i+xx*dx[k])>=n||(j+xx*dy[k])<0||(j+xx*dy[k])>=m) break;
                        int tmp=maze[i+xx*dx[k]][j+xx*dy[k]];
                        if(tmp==6) break;
                        if(tmp>=10){ 
                            maze[i+xx*dx[k]][j+xx*dy[k]]-=10;
                        }
                        xx++;
                    }
                }
            }
            else if(maze[i][j]==2){
                for(int k=0;k<2;k++){
                    int xx=1, sign=1;
                    for(int kk=0;kk<2;kk++){
                        while(1){
                            if((i+sign*xx*dx[k])<0||(i+sign*xx*dx[k])>=n||(j+sign*xx*dy[k])<0||(j+sign*xx*dy[k])>=m) break;
                            int tmp=maze[i+sign*xx*dx[k]][j+sign*xx*dy[k]];
                            if(tmp==6) break;
                            if(tmp==0||tmp>=10){
                                maze[i+sign*xx*dx[k]][j+sign*xx*dy[k]]+=10;
                            }
                            xx++;
                        }
                        xx=1;
                        sign*=-1;
                    }
                    isused[i][j]=true;
                    func(x+1,(m*i)+j+1);
                    isused[i][j]=false;
                    xx=1;
                    for(int kk=0;kk<2;kk++){
                        while(1){
                            if((i+sign*xx*dx[k])<0||(i+sign*xx*dx[k])>=n||(j+sign*xx*dy[k])<0||(j+sign*xx*dy[k])>=m) break;
                            int tmp=maze[i+sign*xx*dx[k]][j+sign*xx*dy[k]];
                            if(tmp==6) break;
                            if(tmp>=10){
                                maze[i+sign*xx*dx[k]][j+sign*xx*dy[k]]-=10;
                            }
                            xx++;
                        }
                        xx=1;
                        sign*=-1;
                    }
                }
            }
            else if(maze[i][j]==3){
                for(int k=0;k<4;k++){
                    int xx=1;
                    for(int kk=0;kk<2;kk++){
                        while(1){
                            if((i+xx*dx[(k+kk)%4])<0||(i+xx*dx[(k+kk)%4])>=n||(j+xx*dy[(k+kk)%4])<0||(j+xx*dy[(k+kk)%4])>=m) break;
                            int tmp=maze[i+xx*dx[(k+kk)%4]][j+xx*dy[(k+kk)%4]];
                            if(tmp==6) break;
                            if(tmp==0||tmp>=10){
                                maze[i+xx*dx[(k+kk)%4]][j+xx*dy[(k+kk)%4]]+=10;
                            }
                            xx++;
                        }
                        xx=1;
                    }
                    isused[i][j]=true;
                    func(x+1,(m*i)+j+1);
                    isused[i][j]=false;
                    xx=1;
                    for(int kk=0;kk<2;kk++){
                        while(1){
                            if((i+xx*dx[(k+kk)%4])<0||(i+xx*dx[(k+kk)%4])>=n||(j+xx*dy[(k+kk)%4])<0||(j+xx*dy[(k+kk)%4])>=m) break;
                            int tmp=maze[i+xx*dx[(k+kk)%4]][j+xx*dy[(k+kk)%4]];
                            if(tmp==6) break;
                            if(tmp>=10){
                                maze[i+xx*dx[(k+kk)%4]][j+xx*dy[(k+kk)%4]]-=10;
                            }
                            xx++;
                        }
                        xx=1;
                    }
                }
            }
            else if(maze[i][j]==4){
                for(int kk=0;kk<4;kk++){
                    int xx=1;
                    for(int k=0;k<4;k++){
                        if(k==kk) continue;
                        while(1){
                            if((i+xx*dx[k])<0||(i+xx*dx[k])>=n||(j+xx*dy[k])<0||(j+xx*dy[k])>=m) break;
                            int tmp=maze[i+xx*dx[k]][j+xx*dy[k]];
                            if(tmp==6) break;
                            if(tmp==0||tmp>=10){
                                maze[i+xx*dx[k]][j+xx*dy[k]]+=10;
                            }
                            xx++;
                        }
                        xx=1;
                    }
                    isused[i][j]=true;
                    func(x+1,(m*i)+j+1);
                    isused[i][j]=false;
                    xx=1;
                    for(int k=0;k<4;k++){
                        if(k==kk) continue;
                        while(1){
                            if((i+xx*dx[k])<0||(i+xx*dx[k])>=n||(j+xx*dy[k])<0||(j+xx*dy[k])>=m) break;
                            int tmp=maze[i+xx*dx[k]][j+xx*dy[k]];
                            if(tmp==6) break;
                            if(tmp>=10){
                                maze[i+xx*dx[k]][j+xx*dy[k]]-=10;
                            }
                            xx++;
                        }
                        xx=1;
                    }
                }
            }
            else if(maze[i][j]==5){
                for(int kk=0;kk<4;kk++){
                    int xx=1;
                    for(int k=0;k<4;k++){
                        while(1){
                            if((i+xx*dx[k])<0||(i+xx*dx[k])>=n||(j+xx*dy[k])<0||(j+xx*dy[k])>=m) break;
                            int tmp=maze[i+xx*dx[k]][j+xx*dy[k]];
                            if(tmp==6) break;
                            if(tmp==0||tmp>=10){
                                maze[i+xx*dx[k]][j+xx*dy[k]]+=10;
                            }
                            xx++;
                        }
                        xx=1;
                    }
                    isused[i][j]=true;
                    func(x+1,(m*i)+j+1);
                    isused[i][j]=false;
                    xx=1;
                    for(int k=0;k<4;k++){
                        while(1){
                            if((i+xx*dx[k])<0||(i+xx*dx[k])>=n||(j+xx*dy[k])<0||(j+xx*dy[k])>=m) break;
                            int tmp=maze[i+xx*dx[k]][j+xx*dy[k]];
                            if(tmp==6) break;
                            if(tmp>=10){
                                maze[i+xx*dx[k]][j+xx*dy[k]]-=10;
                            }
                            xx++;
                        }
                        xx=1;
                    }
                }
            }
        }
        
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
            if(maze[i][j]!=0&&maze[i][j]!=6){
                tvcnt++;
            }
        }
    func(0,0);
    cout<<result;
    return 0;
}