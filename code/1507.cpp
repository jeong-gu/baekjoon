#include <bits/stdc++.h>
using namespace std;
int n;
int d[21][21];
bool arr[21][21];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>d[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool flag=true;
            for(int k=1;k<=n;k++){
                if(k==i||k==j) continue;
                int tmp=d[i][k]+d[k][j];
                if(d[i][j]>tmp){//있을 수 없는 일
                    cout<<-1; 
                    return 0;
                }
                else if(d[i][j]==tmp){//중복 루트
                    flag=false;
                }
            }
            if(flag){
                arr[i][j]=true;
                arr[j][i]=true;
            }
        }
    }
    
    int ans = 0;
    //대각선으로 반갈
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(arr[i][j]) {
                ans += d[i][j];
            }
        }
    }
    cout << ans;
    return 0;
}