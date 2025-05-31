#include <bits/stdc++.h>
using namespace std;
int n,m;
int A[1001][1001];
int B[1001][1001];
int C[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>B[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int mx=INT_MIN;
        for(int j=0;j<n;j++){
            mx=max(mx,abs(A[j][i]-B[j][i]));
        }        
        C[i]=mx;
    }
    int result=0;
    while(m--){
        int tmp; cin>>tmp;
        result+=C[tmp-1];
    }
    cout<<result;
    return 0;
}