#include <bits/stdc++.h>
using namespace std;
int n;
int weight[10001];
vector<int> adj[10001];
vector<int> st[10001][2];
int dp[10001][2];
//m: 0 집합에 있음 , 1 없음
int func(int x,int m,int parent){
    if(dp[x][m]) return dp[x][m];

    int result=0;
    for(auto nxt:adj[x]){
        if(parent==nxt) continue;
        if(m==0){
            result+=func(nxt,1,x);
            for(auto k: st[nxt][1]){
                st[x][m].push_back(k);
            }
        }
        else{
            int tmp1=func(nxt,0,x); 
            int tmp2=func(nxt,1,x);
            if(tmp1<tmp2){
                result+=tmp2;
                for(auto k:st[nxt][1]){
                    st[x][m].push_back(k);
                }
            }
            else{
                result+=tmp1;
                for(auto k:st[nxt][0]){
                    st[x][m].push_back(k);
                }
            }
        }
    }
    if(m==0){
        st[x][m].push_back(x);
        result+=weight[x];
    }
    dp[x][m]=result;
    return dp[x][m];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int result[2];
    for(auto x: {0,1}){
        result[x]=func(1,x,-1);
    }
    if(result[0]<result[1]){
        cout<<result[1]<<"\n";
        sort(st[1][1].begin(),st[1][1].end());
        for(auto x:st[1][1]){
            cout<<x<<" ";
        }
    }
    else{
        cout<<result[0]<<"\n";
        sort(st[1][0].begin(),st[1][0].end());
        for(auto x: st[1][0]){
            cout<<x<<" ";
        }
    }


    return 0;
}