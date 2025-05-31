#include <bits/stdc++.h>
using namespace std;
int arr[301];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m; cin>>m;
    while(m--){
        int l,r; cin>>l>>r;
        int st=l;
        for(int i=0;i<n;i++){
            int x=arr[i];
            if(x>=l&&x<=r){
                cout<<st++<<" ";
            }
            else{
                cout<<x<<" ";
            }
        }
        cout<<"\n";
    }

    return 0;
}
