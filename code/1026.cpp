#include <bits/stdc++.h>
using namespace std;
int d1[51];
int d2[51];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>d1[i];
    }
    for(int i=0;i<n;i++){
        cin>>d2[i];
    }
    sort(d1,d1+n);
    sort(d2,d2+n);
    int result=0;
    for(int i=0;i<n;i++){
        result+=d1[i]*d2[n-i-1];
    }
    cout<<result;
    return 0;
}