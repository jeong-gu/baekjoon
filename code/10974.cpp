#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10];
bool isused[10];
void func(int x){
    if(x==n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!isused[i]){
            isused[i]=true;
            arr[x]=i;
            func(x+1);
            isused[i]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    func(0);   
    return 0;
}