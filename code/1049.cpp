#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    int pack=INT_MAX;
    int one=INT_MAX;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        pack=min(pack,a);
        one=min(one,b);
    }
    int res=0;
    int cnt=0;
    while(cnt<=n-6){
        res+=min(pack,6*one);
        cnt+=6;
    }
    res+=min(pack,(n-cnt)*one);
    cout<<res;
    return 0;
}