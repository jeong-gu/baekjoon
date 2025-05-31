#include <bits/stdc++.h>
using namespace std;
int d[11];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=0;i<n;i++) cin>>d[i];

    int cnt=0;
    for(int i=n;i>0;i--){
        cnt+=k/d[i-1];
        k%=d[i-1];
    }
    cout<<cnt;
    
    return 0;
}