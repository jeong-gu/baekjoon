#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
bool isused1[15];
bool isused2[40];
bool isused3[40];
void func(int k){
    if(k==n){
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
            if(isused1[i]||isused2[k+i]||isused3[k-i+n-1])
                continue;
            isused1[i]=true;
            isused2[k+i]=true;
            isused3[k-i+n-1]=true;
            func(k+1);
            isused1[i]=false;
            isused2[k+i]=false;
            isused3[k-i+n-1]=false;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    func(0);
    cout<<cnt;
    return 0;
}