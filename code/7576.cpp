#include <iostream>
#include <deque>
using namespace std;
int arr[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
deque<pair<int, int>> deq;
deque<pair<int, int>> deqdeq;
bool visited[1001][1001] = { false, };


int main() {
    int width, height, done=0,cnt=0;
    cin >> width >> height;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                deq.push_back(make_pair(i, j));
                done++;
            }
            else if (arr[i][j] == -1)done++;
        }
    }
    if (done == width * height) {
        cout << "0"; return 0;
    }
    while (!deq.empty() || !deqdeq.empty()) {
        if (!deq.empty()) {
            while (!deq.empty()) {
                pair<int, int> tmp = deq.front();
                deq.pop_front();
                for (int i = 0; i < 4; i++) {
                    int x = tmp.first + dx[i];
                    int y = tmp.second + dy[i];
                    if (x<1 || x>height || y<1 || y>width)continue;

                    if (arr[x][y] == 0 && !visited[x][y]) {
                        arr[x][y] = 1;
                        done++;
                        deqdeq.push_back(make_pair(x, y));
                        visited[x][y] = true;
                    }
                }
            }
            cnt++;
        }
        else {
            while (!deqdeq.empty()) {
                pair<int, int> tmp = deqdeq.front();
                deqdeq.pop_front();
                for (int i = 0; i < 4; i++) {
                    int x = tmp.first + dx[i];
                    int y = tmp.second + dy[i];
                    if (x<1 || x>height || y<1 || y>width)continue;

                    if (arr[x][y] == 0 && !visited[x][y]) {
                        arr[x][y] = 1;
                        done++;
                        deq.push_back(make_pair(x, y));
                        visited[x][y] = true;
                    }
                }
            }
            cnt++;
        }
    }
    if (done != width * height) {
        cout << "-1"; 
        return 0;
    }
    cout << cnt-1;
    return 0;
}