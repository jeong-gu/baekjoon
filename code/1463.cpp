#include <bits/stdc++.h>
using namespace std;
int arr[1000010];
int func(int mode,int i){
    if(mode==1){
        return i*3;
    }
    if(mode==2){
        return i*2;
    }
    if(mode==3){
        return i+1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    fill(arr,arr+1000010,0x3f3f3f3f);
    int n; cin>>n;
    arr[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            int tmp=func(j,i);
            if(tmp>n) continue;
            arr[tmp]=min(arr[tmp],arr[i]+1);
        }
    }

    cout<<arr[n];
    return 0;
}