#include <bits/stdc++.h>
using namespace std;
int n,result=0;
int board[25][25];
void rotate(int tmp[25][25]){
    int ttmp[25][25];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        ttmp[i][j]=tmp[i][j];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        tmp[i][j]=ttmp[n-1-j][i];
}
void func(int x){
    if(x==5){
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(board[i][j]>result)
            result=board[i][j];
            return;
    }
    int tmp[25][25];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        tmp[i][j]=board[i][j];
    }
    for(int t=0;t<4;t++){
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            board[i][j]=tmp[i][j];
            
        queue<int> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(board[i][j]!=0)
                    q.push(board[i][j]);
            fill(board[i],board[i]+n,0);
            int j=0;
            while(!q.empty()){
                int qtmp=q.front();
                q.pop();
                if(!q.empty()&&qtmp==q.front()){
                    board[i][j]=qtmp*2;
                    q.pop();
                }
                else
                    board[i][j]=qtmp;
                j++;
            }
        }
        func(x+1);
        rotate(tmp);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        cin>>board[i][j]; 
        result=(result<board[i][j])
            ?board[i][j]:result;
    }
    
    func(0);
    cout<<result;
    return 0;
}