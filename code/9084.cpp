#include <bits/stdc++.h>
using namespace std; 
int arr[10005];
int d[10005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        fill(d,d+10005,0);
        int n; cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        d[0]=1;
        int x;
        cin>>x;
        for(int i=0;i<n;i++){
            for(int j=arr[i];j<=x;j++){
                d[j]+=d[j-arr[i]];
            }
        }
        cout<<d[x]<<"\n";
    }

    return 0;
}