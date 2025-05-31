#include <bits/stdc++.h>
using namespace std;
int d[201][201];
int mod=1000000000;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=0;i<=n;i++){
        d[i][1]=1;
    }
    for(int l=2;l<=k;l++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
                d[i][l]+=d[j][l-1];
                d[i][l]%=mod;
            }
        }
    }
    cout<<d[n][k];


    return 0;
}