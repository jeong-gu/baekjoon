#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    while(n--){
        ll a,b; cin>>a>>b;
        vec.push_back(a*a+b*b);
    }
    sort(vec.begin(),vec.end());

    int r; cin>>r;

    ll r2=r*r;
    ll tmp,ans;
    ll mx=-1;
    for(int i=1;i<m;i++){
        int tmp=upper_bound(vec.begin(),vec.end(),r2+r*r)-lower_bound(vec.begin(),vec.end(),r2);
        if(mx<tmp){
            mx=tmp;
            ans=i+1;
        }
        r2+=r*r;
    }
    cout<<ans;

    return 0;
}