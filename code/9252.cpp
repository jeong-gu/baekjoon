#include <bits/stdc++.h>    
using namespace std;
string a;
string b;
int d[1001][1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b;
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            if(a[i]==b[j]){
                d[i+1][j+1]=d[i][j]+1;
            }
            else{
                if(d[i][j+1]<d[i+1][j]){
                    d[i+1][j+1]=d[i+1][j];
                }
                else{
                    d[i+1][j+1]=d[i][j+1];
                }
            }
        }
    }

    string s;

	int i = a.length();
	int j = b.length();
	while (i > 0 && j > 0){
		if (d[i][j] == d[i - 1][j]){
			--i;
		}
		else if (d[i][j] == d[i][j - 1]){
			--j;
		}
		else{
			s+=a[i-1];
			--i;
			--j;
		}
	}

	cout << s.length() << '\n';
	for (int i = s.length() - 1; i >= 0; i--){
		cout << s[i];
	}


    return 0;
}