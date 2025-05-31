#include <bits/stdc++.h>    
using namespace std;
int INF=987654321;
class edge{
public:
    int s,e,t;
};
bool func(int n,vector<edge> vec){
    vector<int> dp(n+1,INF);
    dp[1]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<vec.size();j++){
            int s=vec[j].s;
            int e=vec[j].e;
            int t=vec[j].t;
            if(dp[e]>dp[s]+t){
                dp[e]=dp[s]+t;
            }
        }
    }
    for(int j=0;j<vec.size();j++){
        int s=vec[j].s;
        int e=vec[j].e;
        int t=vec[j].t;
        if(dp[e]>dp[s]+t){
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin>>k;
    while(k--){
        vector<edge> vec;
        int n,m,w; cin>>n>>m>>w;
        for(int i=0;i<m;i++){
            int s,e,t; cin>>s>>e>>t;
            vec.push_back({s,e,t});
            vec.push_back({e,s,t});
        }
        for(int i=0;i<w;i++){
            int s,e,t; cin>>s>>e>>t;
            vec.push_back({s,e,-t});
        }
        if(func(n,vec)) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}