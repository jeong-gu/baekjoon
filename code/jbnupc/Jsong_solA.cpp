#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,ans; cin>>n>>m;
    
    if(n<=m) ans=m;
    else{
        ans=m+2*(3*((n-m)/4)+(n-m)%4);//2* 올라갔다 내려가기
    }
    cout<<ans-1;
}
