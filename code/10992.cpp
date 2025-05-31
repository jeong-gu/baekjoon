#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int cnt=1;
    for(int i=0;i<n-1;i++) cout<<" ";
    cout<<"*\n"; 
    for(int i=n-2;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<"*";
        for(int j=0;j<cnt;j++){
            cout<<" ";
        }
        cnt+=2;
        cout<<"*\n";
    }
    if(n==1) return 0;
    for(int i=0;i<2*n-1;i++){
        cout<<"*";
    }
    return 0;
}