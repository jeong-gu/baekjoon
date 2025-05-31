#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    double f, g, h;

    bool operator<(const Point& other) const {
        if (f != other.f)
            return f > other.f; // 우선순위 큐에서 f 값이 작은 순으로 정렬
        if (x != other.x)
            return x > other.x; // x 값이 작은 순
        return y > other.y;     // y 값이 작은 순
    }
};

// 유클리디안 거리 계산 함수
double euclidean_dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// A* 알고리즘 구현
pair<vector<Point>, double> a_star(const vector<vector<int>>& grid, Point start, Point goal) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<double>> g_values(n, vector<double>(m, 1e9));
    vector<vector<Point>> came_from(n, vector<Point>(m, {-1, -1, 0, 0, 0}));

    priority_queue<Point> pq;

    start.g = 0;
    start.h = euclidean_dist(start.x, start.y, goal.x, goal.y);
    start.f = start.g + start.h;
    pq.push(start);
    g_values[start.x][start.y] = 0;

    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

    while (!pq.empty()) {
        Point current = pq.top();
        pq.pop();

        if (visited[current.x][current.y])
            continue;
        visited[current.x][current.y] = true;

        if (current.x == goal.x && current.y == goal.y) {
            // 경로 재구성
            vector<Point> path;
            Point trace = current;
            double total_cost = current.g;

            while (trace.x != -1 && trace.y != -1) {
                path.push_back(trace);
                trace = came_from[trace.x][trace.y];
            }
            reverse(path.begin(), path.end());
            return {path, total_cost};
        }

        for (int i = 0; i < 8; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 1 || visited[nx][ny])
                continue;

            double cost = (i < 4) ? 1.0 : sqrt(2.0); // 상하좌우는 1, 대각선은 sqrt(2)
            double tentative_g = current.g + cost;

            if (tentative_g < g_values[nx][ny]) {
                g_values[nx][ny] = tentative_g;

                Point neighbor = {nx, ny, 0, tentative_g, 0};
                neighbor.h = euclidean_dist(nx, ny, goal.x, goal.y);
                neighbor.f = neighbor.g + neighbor.h;

                pq.push(neighbor);
                came_from[nx][ny] = current;
            }
        }
    }

    return {{}, -1}; // 경로를 찾을 수 없는 경우
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Point start = {x1 - 1, y1 - 1, 0, 0, 0};
    Point en = {x2 - 1, y2 - 1, 0, 0, 0};

    auto result = a_star(vec, start, en);
    vector<Point> path = result.first;
    double cost = result.second;

    if (cost == -1) {
        cout << -1 << endl;
    } else {
        for (const auto& p : path) {
            cout << "(" << p.x + 1 << ", " << p.y + 1 << ") ";
            if (&p != &path.back()) cout << "-> ";
        }
        cout << endl;
        cout << fixed << setprecision(2) << cost << endl;
    }

    return 0;
}
