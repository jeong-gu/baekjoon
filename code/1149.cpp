#include <bits/stdc++.h>
using namespace std;
int n; 
int r[1001];
int g[1001];
int b[1001];
int arr[3][1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>r[i]>>g[i]>>b[i];
    } 
    arr[0][1]=r[1];
    arr[1][1]=g[1];
    arr[2][1]=b[1];
    for(int i=2;i<=n;i++){
        arr[0][i]=min(arr[1][i-1],arr[2][i-1])+r[i];
        arr[1][i]=min(arr[0][i-1],arr[2][i-1])+g[i];
        arr[2][i]=min(arr[1][i-1],arr[0][i-1])+b[i];
    }
    cout<<min({arr[0][n],arr[1][n],arr[2][n]});
    return 0;
}