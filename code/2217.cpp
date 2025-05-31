#include <bits/stdc++.h>
using namespace std;

int n;
int d[100005];

int main(void){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> d[i];
  sort(d, d+n);
  int ans = 0;
  for(int i = 1; i <= n; i++)
    ans = max(ans, d[n-i]*i);
  cout << ans;
}