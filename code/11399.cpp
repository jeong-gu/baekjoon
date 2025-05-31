#include <bits/stdc++.h>
using namespace std;
int d[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    sort(d,d+n);
    for(int i=1;i<n;i++){
        d[i]+=d[i-1];
    }
    int result=0;
    for(int i=0;i<n;i++){
        result+=d[i];
    }
    cout<<result;
    return 0;
}


