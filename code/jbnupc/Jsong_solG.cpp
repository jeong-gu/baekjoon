// #include <bits/stdc++.h>
// using namespace std;

// int n;
// int arr[1000001];
// int cycle[1000001];
// bool realVisited[1000001];
// bool swt;

// int dfs(int st, int cur, int cnt,vector<int> &vec,vector<bool> &visited) {
//     int nxt = arr[cur];

//     if(realVisited[nxt]) return cycle[nxt];
//     if (visited[nxt]) {
//         if(st==nxt) {
//             swt=true;
//             return cnt;
//         }
//         return -1;
//     }

//     visited[nxt] = true;
//     vec.push_back(nxt);
//     return dfs(st, nxt, cnt + 1,vec,visited);
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
    
//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> arr[i];

//     int res = -1;
//     for (int i = 1; i <= n; i++) {
//         if (!cycle[i]) { 
//             vector<bool> visited(n+1);
//             visited[i] = true; 
//             swt=false;
//             vector<int> vec;
//             cycle[i] = dfs(i,i,1,vec,visited);
//             if(swt){
//                 for(auto x: vec) realVisited[x]=true;
//             }
//             res = max(res, cycle[i]);
//         }
//     }

//     cout << res;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int vis[1000001];
bool finished[1000001];
int ans;

void dfs(int cur, int d) {
    vis[cur] = d;
    int nxt = arr[cur];

    if (vis[nxt] == 0) {
        dfs(nxt, d + 1);
    }
    else if (!finished[nxt]) {
        ans = max(ans, d - vis[nxt] + 1);
    }

    finished[cur] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i, 1);
        }
    }

    cout << ans;
    return 0;
}
