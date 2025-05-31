#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int l,k,c; cin>>l>>k>>c;
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    sort(arr,arr+k);
    int st=1, en=1000000000;
    while(st<en){
        int idx=0;
        int mid=(st+en)/2;
        while(idx<=en){
            idx=lower_bound(arr+idx,arr+)
        }
    }


    return 0;
}