#include <bits/stdc++.h>    
using namespace std;
string arr[501];
int karr[501][501][26];
char mxchArr[501][501];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            karr[i%k][j%k][arr[i][j]-65]++;
        }
    }
    int ans=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            char mxch;
            int mxcnt=0;
            for(int l=0;l<26;l++){
                if(mxcnt<karr[i][j][l]){
                    mxcnt=karr[i][j][l];
                    mxch=l+65;
                }
            }
            mxchArr[i][j]=mxch;
            ans+=(n*m)/(k*k)-mxcnt;
        }
    }

    cout<<ans<<"\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mxchArr[i%k][j%k];
        }
        cout<<"\n";
    }

    return 0;
}