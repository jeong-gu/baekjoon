#include <bits/stdc++.h>
using namespace std;
bool arr[101][101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    while(n--){
        int x,y; cin>>x>>y;
        for(int i=x;i<x+10;i++)
        for(int j=y;j<y+10;j++)
            arr[i][j]=true;
    }
    int result=0;
    for(int i=1;i<101;i++)
    for(int j=1;j<101;j++)
        if(arr[i][j]) result++;
    cout<<result;
    return 0;
}