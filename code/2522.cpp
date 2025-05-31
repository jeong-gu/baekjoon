#include <bits/stdc++.h>
using namespace std;
void func(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i-1;j>0;j--){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    n--;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<" ";
        }
        for(int j=n-i-1;j>=0;j--){
            cout<<"*";
        }
        cout<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;  
    func(n);
    return 0;
}