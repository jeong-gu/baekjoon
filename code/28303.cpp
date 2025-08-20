#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[500001];
ll arr2[500001];
ll ans=-(0x5f5f5f5f5f);
ll mn;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++){
        arr2[i]=arr[i]-k*i;
    }   
    mn=arr2[0];
    for(int i=1;i<n;i++){
        ans=max(ans,arr2[i]-mn);
        mn=min(mn,arr2[i]);
    }
    reverse(arr,arr+n);
    for(int i=0;i<n;i++){
        arr2[i]=arr[i]-k*i;
    }   
    mn=arr2[0];
    for(int i=1;i<n;i++){
        ans=max(ans,arr2[i]-mn);
        mn=min(mn,arr2[i]);
    }
    cout<<ans;


    return 0;
}