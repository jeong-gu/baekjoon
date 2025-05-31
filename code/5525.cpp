#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    string str; cin>>str;
    int ans=0;
    for (int i = 0; i < m; i++) {
		int k = 0; 
		if (str[i] == 'O') continue;

		while (str[i + 1] == 'O' && str[i + 2] == 'I') {
			k++;
			if (k == n) {
				ans++;
				k--; 
			}
			i += 2;
		}
	}
    cout<<ans<<"\n";

    return 0;
}