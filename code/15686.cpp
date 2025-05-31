#include <bits/stdc++.h>
using namespace std;

int n, m;
int maze[51][51];
int mn = INT_MAX;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

//multi-source-bfs
int bfs(const vector<int>& selectedChicken) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    int totalDistance = 0;

    for (int idx : selectedChicken) {
        int cx = chickens[idx].first;
        int cy = chickens[idx].second;
        q.push({cx, cy});
        dist[cx][cy] = 0;
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n || dist[nx][ny] != -1) {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (auto& house : houses) {
        int hx = house.first;
        int hy = house.second;

        int minDist = INT_MAX;
        if (dist[hx][hy] != -1) {
            minDist = dist[hx][hy];
        }
        totalDistance += minDist;
    }

    return totalDistance;
}

void func(int c, int idx, vector<int>& selectedChicken) {
    if (c == m) {
        int distance = bfs(selectedChicken);
        mn = min(mn, distance);
        return;
    }

    for (int i = idx; i < chickens.size(); i++) {
        selectedChicken.push_back(i);
        func(c + 1, i + 1, selectedChicken);
        selectedChicken.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 1) {
                houses.push_back({i, j});
            } else if (maze[i][j] == 2) {
                chickens.push_back({i, j});
            }
        }
    }

    vector<int> selectedChicken;
    func(0, 0, selectedChicken);

    cout << mn << '\n';
    return 0;
}
