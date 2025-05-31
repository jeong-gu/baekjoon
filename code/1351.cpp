#include <bits/stdc++.h>
using namespace std;

unordered_map<long long int,long long int> dp;

long long int func(long long int n,long long int p,long long int q){
    if(n==0)
        return 1;
    if(dp.count(n)) return dp[n];
    long long int tmp1=func(n/p,p,q);
    long long int tmp2=func(n/q,p,q);
    dp[n]=tmp1+tmp2;
    return dp[n];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    long long int n,p,q; cin>>n>>p>>q;
    cout<<func(n,p,q);
    return 0;
}