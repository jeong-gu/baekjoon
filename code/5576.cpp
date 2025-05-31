#include <bits/stdc++.h>
using namespace std;
int a[10];
int b[10];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n=2;
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    sort(a,a+10);
    for(int i=0;i<10;i++){
        cin>>b[i];
    }
    sort(b,b+10);
    cout<<a[7]+a[8]+a[9]<<" "<<b[7]+b[8]+b[9];

    return 0;
}