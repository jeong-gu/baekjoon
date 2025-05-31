#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,input;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        arr[input]++;
    }
    int j=0;
    for(auto i:arr){
        while(i--){
            cout<<j<<"\n";
        }
        j++;
    }
    return 0;
}