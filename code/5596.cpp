#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int result=0;
    int tmp=0;
    for(int i=0;i<4;i++){
        int c; cin>>c;
        tmp+=c;
    }
    result=max(result,tmp);
    tmp=0;
    for(int i=0;i<4;i++){
        int c; cin>>c;
        tmp+=c;
    }
    result=max(result,tmp);
    cout<<result;
    return 0;
}