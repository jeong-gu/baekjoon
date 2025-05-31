#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int dp[105][105]; 
int p[105];       

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n; 

    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a>>b;
        p[i]=a;
        if(i==n-1){
            p[i+1]=b;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0; 
    }

    // DP 테이블 채우기
    for (int len = 2; len <= n; len++) { // 부분 문제 크기 (길이)
        for (int i = 1; i <= n - len + 1; i++) { // 시작 인덱스
            int j = i + len - 1; // 끝 인덱스
            dp[i][j] = INF; // 최소값을 찾기 위해 초기화
            for (int k = i; k < j; k++) { // 분할점
                int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // 최소 곱셈 연산 횟수 출력
    cout << dp[1][n] << '\n';

    return 0;
}
