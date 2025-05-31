#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> vec;
int dp[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int d,p; cin>>d>>p;
    for(int i=0;i<p;i++){
        int l,c; cin>>l>>c;
        vec.push_back({l,c});
    }
    for(int i=1;i<=d;i++){
        dp[i]=0;
    }
    dp[0]=INT_MAX;

    for(auto x:vec) {
        for (int i =d;i>=1;i--) {
            int prev=i-x.first;
            if(prev<0)continue;
            dp[i] = max(dp[i], min(dp[prev], x.second));
        }
    }
    cout<<dp[d];

    return 0;
}