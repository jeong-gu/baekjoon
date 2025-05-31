#include <bits/stdc++.h>
using namespace std;
char box[4]={'D','S','L','R'};
string dp[10001];
bool visited[10001];
int a,b;
void func(){
    queue<int> q;
    q.push(a);
    dp[a]="";
    visited[a]=true;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        int x[4];
        x[0]=(2*tmp)%10000;
        x[1]=(tmp-1<0)?9999:tmp-1;
        
        int f=tmp/1000;
        x[2]=(tmp*10)%10000+f;
        
        f=tmp%10;
        x[3]=int(tmp/10);
        x[3]+=1000*f;
        for(int i=0;i<4;i++){
            if(visited[x[i]]) continue;
            q.push(x[i]);
            visited[x[i]]=true;
            dp[x[i]]=dp[tmp]+box[i];
        }
        if(visited[b]) return;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>a>>b;
        func();
        cout<<dp[b]<<"\n";
        fill(visited,visited+10001,false);
    }


    return 0;
}