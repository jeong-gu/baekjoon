#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100001];
int dp[100001][2];
int func(int x,int parent,int m){
    if(dp[x][m]) return dp[x][m];
    int result=0;
    for(auto child:vec[x]){
        if(parent==child) continue;
        if(m==0){
            result+=func(child,x,!m);
        }
        else{
            result+=min(func(child,x,m),func(child,x,!m));
        }
    }
    if(m==1) result+=1;
    dp[x][m]=result;
    return dp[x][m];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    n--;
    while(n--){
        int a,b; cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int ans=min(func(1,-1,0),func(1,-1,1));
    cout<<ans;
    return 0;
}