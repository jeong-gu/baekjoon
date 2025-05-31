#include <iostream>
#include <queue>
using namespace std;
char arr[100][100];
int visited[100][100] = {0,};
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
    int n, m;
    cin >> n >> m;
    queue<pair<int,int>> que;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    que.push(make_pair(0, 0));
    visited[0][0] = 1;
    int min = 100000;
    while (!que.empty()) {
        pair<int, int> tmp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m)continue;
            if (x == n - 1 && y == m - 1) {
                if (visited[n - 1][m - 1] ==0||
                    visited[tmp.first][tmp.second] + 1
                    < visited[n - 1][m - 1]) {
                    visited[n - 1][m - 1] =
                        visited[tmp.first][tmp.second]+1;
                    min = visited[x][y];
                }
            }
            if (visited[x][y] == 0 && arr[x][y] == '1') {
                que.push(make_pair(x, y));
                visited[x][y] = visited[tmp.first][tmp.second] + 1;
            }
        }
    }
    cout << min;
    return 0;
}