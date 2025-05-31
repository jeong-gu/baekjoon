#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
int isused[10];
void func(int x){
    if(x==m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(isused[i]!=m){
            arr[x]=i;
            isused[i]++;
            func(x+1);
            isused[i]--;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    func(0);
    return 0;
}