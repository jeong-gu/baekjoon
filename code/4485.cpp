#include <bits/stdc++.h>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int INF=987654321;
int mz[126][126];
int dp[126][126];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int cnt=0;
    while(1){
        int n; cin>>n;
        if(n==0) break;
        cnt++;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>mz[i][j];
        for(int i=0;i<n;i++)
            fill(dp[i],dp[i]+n,INF);
        dp[0][0]=mz[0][0];
        pq.push({mz[0][0],0,0});
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            if(dp[get<1>(cur)][get<2>(cur)]!=get<0>(cur)) continue;
            for(int i=0;i<4;i++){
                int nx=get<1>(cur)+dx[i];
                int ny=get<2>(cur)+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n) continue;
                if(dp[nx][ny]>dp[get<1>(cur)][get<2>(cur)]+mz[nx][ny]){
                    dp[nx][ny]=dp[get<1>(cur)][get<2>(cur)]+mz[nx][ny];
                    pq.push({dp[nx][ny],nx,ny});
                }
            }
        }
        cout<<"Problem "<<cnt<<": "<<dp[n-1][n-1]<<"\n";

    }



    return 0;
}