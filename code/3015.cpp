#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    stack<pair<int, int>> stk;
    int n; cin >> n;
    long long cnt = 0;  
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int sameHeight = 1;

        while (!stk.empty() && stk.top().first <= x) {
            cnt += stk.top().second;  
            if (stk.top().first == x) {
                sameHeight += stk.top().second;   
            }
            stk.pop();
        }
 
        if (!stk.empty()) cnt++;

 
        stk.push({x, sameHeight});
    }

    cout << cnt << "\n";
    return 0;
}
