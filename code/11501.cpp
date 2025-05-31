#include <bits/stdc++.h>
using namespace std;

int d[1000001];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    for(int i=0;i<n;++i) cin>>d[i];
    int max_val = d[n-1];
    long long ans = 0;
    for(int i=n-2;i>=0;--i) {
      if(d[i] > max_val) max_val = d[i];
      ans += max_val - d[i];
    }
    cout<<ans<<'\n';
  }
}




