#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt;
int a[1000001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>cnt;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll mx=-1;
    ll st=0,en=a[n-1],mid;
    while(st<en){
        mid=(st+en)/2;
        ll tmp=0;
        for(int i=0;i<n;i++){
            if(a[i]-mid>0){
                tmp+=a[i]-mid;
            }
        }
        if(tmp>=cnt){
            st=mid+1;
            mx=max(mx,mid);
        }
        else{
            en=mid;
        }
    }
    cout<<mx;
    return 0;
}