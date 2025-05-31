#include <bits/stdc++.h>
using namespace std;

// 소수 판별 함수
bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// 가장 작은 소수 찾기
int find_next_prime(int start) {
    while (!is_prime(start)) {
        start++;
    }
    return start;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    // 해시 테이블 크기 M 계산
    int M = find_next_prime(2 * N);

    // 해시 테이블 초기화
    vector<int> hash_table(M, -1); // -1은 비어 있는 슬롯을 의미
    int collisions = 0;

    // 숫자 삽입 및 충돌 횟수 계산
    for (int num : nums) {
        int h = num % M;
        while (hash_table[h] != -1) { // 충돌 발생
            collisions++;
            h = (h + 1) % M; // 다음 슬롯으로 이동
        }
        hash_table[h] = num;
    }

    // 결과 출력
    cout << collisions << '\n';

    return 0;
}
