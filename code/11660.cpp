#include <bits/stdc++.h>
using namespace std;
int n,m;
int box[1100][1100];
int sum[1100][1100];
int func(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>box[i][j];
            sum[i][j]=box[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    while(m--){
        cout<<func()<<"\n";
    }
    return 0;
}