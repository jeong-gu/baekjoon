#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
int isused[10];
void func(int x,int min){
    if(x==m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=min;i<=n;i++){
        if(isused[i]!=m){
            arr[x]=i;
            isused[i]++;
            func(x+1,i);
            isused[i]--;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;    
    func(0,1);
    return 0;
}