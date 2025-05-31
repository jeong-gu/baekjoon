#include <bits/stdc++.h>
using namespace std;
int x[100001];
int d[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    while(m--){
        int a,b,k; cin>>a>>b>>k;
        d[a]+=k;
        d[b+1]-=k;
    }
    int now=0;
    for(int i=1;i<=n;i++){
        now+=d[i];
        d[i]=now;
        cout<<x[i]+d[i]<<" ";
    }
    
    return 0;
}