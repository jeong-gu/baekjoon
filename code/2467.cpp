#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> vec(100005);
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    pair<ll,ll> ans={1<<31,1<<31};
    for(int i=0;i<n;i++){
        int idx=lower_bound(vec.begin(),vec.begin()+n,-vec[i])-vec.begin();
        if(idx+1<n&&i!=idx+1&&abs(vec[i]+vec[idx+1])<=abs(ans.first+ans.second)){
            ans={vec[i],vec[idx+1]};
        }
        if(idx<n&&i!=idx&&abs(vec[i]+vec[idx])<=abs(ans.first+ans.second)){
            ans={vec[i],vec[idx]};
        }
        if(idx!=0&&i!=idx-1&&abs(vec[i]+vec[idx-1])<=abs(ans.first+ans.second)){
            ans={vec[i],vec[idx-1]};
        }
    }
    if(ans.first>ans.second) swap(ans.first,ans.second);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}