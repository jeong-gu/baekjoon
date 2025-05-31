#include <bits/stdc++.h>
using namespace std;

int n; 
int a[101][101];
int d[101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        queue<int> q;
        int visited[n];
        fill(visited,visited+n,0);

        q.push(i);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int j = 0; j < n; j++) {
                if (a[x][j] && !visited[j]) {
                    visited[j] = 1;
                    d[i][j] = 1;
                    q.push(j);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
