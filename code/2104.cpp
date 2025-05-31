#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100001];
ll solve(int st,int en){
    if(st==en){
        return a[st]*a[st];
    }
    ll mid=(st+en)/2;
    ll left=solve(st,mid);
    ll right=solve(mid+1,en);
    ll result=max(left,right);
    
    ll l=mid,r=mid+1;
    ll minvalue=min(a[l],a[r]);
    ll maxsum=a[l]+a[r];
    result=max(result,maxsum*minvalue);
    while(st<l||en>r){
        if(r<en&&(st==l||a[l-1]<a[r+1])){
            maxsum+=a[++r];
            minvalue=min(minvalue,a[r]);
        }
        else{
            maxsum+=a[--l];
            minvalue=min(minvalue,a[l]);
        }
        result=max(result,maxsum*minvalue);
    }
    return result;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(0,n);


    return 0;
}