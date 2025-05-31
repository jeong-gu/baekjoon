s#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[10005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            auto tmp1=upper_bound(a+j+1,a+n,-a[i]-a[j]);
            auto tmp2=lower_bound(a+j+1,a+n,-a[i]-a[j]);
            cnt+=tmp1-tmp2;
        }
    }
    cout<<cnt;
    return 0;
}