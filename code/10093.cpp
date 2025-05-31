#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    long long n,m;
    cin>>n>>m;
    if(n==m){
        cout<<"0"; return 0;
    }
    else if(n>m){
        swap(n,m);
    }
    cout<<m-n-1<<"\n";
    for(long long i=n+1;i<m;i++){
        cout<<i<<" ";
    }
    return 0;
}