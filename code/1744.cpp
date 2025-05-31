#include <bits/stdc++.h>
using namespace std;
int d[51];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    sort(d,d+n);
    int result=0;
    for(int i=n-1;i>=0;i-=2){
        if(i==0){
            result+=d[i];
        }
        result+=max(d[i]*d[i-1],d[i]+d[i-1]);
    }
    cout<<result;

    return 0;
}