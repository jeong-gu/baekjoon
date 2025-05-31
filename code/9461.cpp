#include <bits/stdc++.h>
using namespace std;
long long int d[101];
int main(){
    d[1]=1; d[2]=1; d[3]=1;
    for(int i=4;i<=100;i++){
        d[i]=d[i-2]+d[i-3];
    }

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<d[n]<<"\n";
    }


    return 0;
}