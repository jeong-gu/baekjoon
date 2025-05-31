#include <bits/stdc++.h>
using namespace std;

vector<int> adj[30001]; // 인접 리스트
bool visited[30001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 그래프 입력 (인접 리스트 생성)
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int result = 0;

    // BFS를 사용하여 연결 요소 탐색
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        queue<int> q;
        q.push(i);
        visited[i] = true;

        int cnt = 0; // 현재 연결 요소의 크기

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            cnt++;

            for (int next : adj[cur]) {
                if (visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }

        result = max(result, cnt); // 최대 크기 갱신
    }

    cout << result << '\n';

    return 0;
}
