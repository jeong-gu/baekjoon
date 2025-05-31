#include <bits/stdc++.h>
using namespace std;
int A[1000001];
int B[1000001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<m;i++){
        cin>>B[i];
    }
    A[n]=0x7f7f7f7f;
    B[m]=0x7f7f7f7f;
    int cntA=0,cntB=0;
    for(int i=0;i<n+m;i++){
        if(A[cntA]<B[cntB]){
            cout<<A[cntA]<<" ";
            cntA++;
        }
        else{
            cout<<B[cntB]<<" ";
            cntB++;
        }
    }
    return 0;
}



