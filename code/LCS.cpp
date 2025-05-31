#include <bits/stdc++.h>
using namespace std;

int d[1001][1001]; // 문자열의 길이를 고려하여 배열 크기 제한

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.length();
    int m = str2.length();

    // DP 배열 채우기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) { // 문자열은 0-based 인덱싱
                d[i][j] = d[i - 1][j - 1] + 1;
            } else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    // LCS 길이 출력
    cout << d[n][m] << '\n';

    return 0;
}
