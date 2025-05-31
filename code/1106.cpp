#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int dp[10001];
int INF=0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int c,n; cin>>c>>n;
    for(int i=0;i<n;i++){
        int cost,people;
        cin>>cost>>people;
        if(mp.count(people)){
            if(mp[people]>cost){
                mp[people]=cost;
            }
        }
        else{
            mp[people]=cost;
        }
    }
    fill(dp,dp+10001,INF);
    dp[0]=0;
    for(auto x:mp){
        dp[x.first]=min(dp[x.first],x.second);
    }

    for(int i=1;i<c+101;i++){
        for(auto x:mp){
            int prev=i-x.first;
            if(prev<0) continue;
            dp[i]=min(dp[prev]+x.second,dp[i]);
        }
    }

    cout<<*min_element(dp+c,dp+c+101);
    return 0;
}

