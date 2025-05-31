#include <bits/stdc++.h>
using namespace std;
int point[100001];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, x, y; cin >> n >> m;

  for (int i = 0; i < n; i++) cin >> point[i];

  sort(point, point + n);
  for (int i = 0; i < m; i++){
    cin >> x >> y;
    cout << upper_bound(point, point + n, y) - lower_bound(point, point + n, x) << "\n";
  }
  return 0;
}