#include <bits/stdc++.h>
using namespace std;
int n,k;
int w[101];
int v[101];
int d[101][100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int l=1;l<=k;l++){
        for(int i=1;i<=n;i++){
            if(l-w[i]<0){
                d[i][l]=d[i-1][l];
            }
            else{
                d[i][l]=max(d[i-1][l],d[i-1][l-w[i]]+v[i]);
            }
        }
    }
    cout<<d[n][k];

    return 0;
}