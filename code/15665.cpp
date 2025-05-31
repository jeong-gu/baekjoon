#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[10];
int out[10];
int isused[10001];
void func(int x) {
	if (x == m) {
		for (int i = 0; i < m; i++) {
			cout << out[i] << " ";
		}
		cout << "\n";
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (isused[i] != m && tmp != arr[i]) {
			out[x] = arr[i];
			isused[i]++;
			tmp = arr[i];
			func(x + 1);
			isused[i]--;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0);
	return 0;
}