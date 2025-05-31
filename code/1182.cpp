#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
int arr[21];
void func(int x,int sum){
    if(sum==m&&x!=0){
        cnt++;
    }
    if(x==n) return;

    for(int i=x;i<n;i++){
        if(arr[i]<0){
                func(i+1,sum+arr[i]);
        }
        else{
                func(i+1,sum+arr[i]);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    func(0,0);
    cout<<cnt;
    return 0;
}