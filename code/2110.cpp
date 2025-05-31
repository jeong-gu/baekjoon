#include <bits/stdc++.h>    
using namespace std;
int n,c;
int a[200005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int st=1,en=1000000000;
    while(st<en){
        int mid=(st+en+1)/2;
        int idx=0,cnt=0;
        while(idx!=n){
            idx=lower_bound(a+idx,a+n,a[idx]+mid)-a;
            cnt++;
        }
        if(cnt>=c){
            st=mid;
        }
        else{
            en=mid-1;
        }
    }
    cout<<st;
    return 0;
}