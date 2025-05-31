#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int num;
    int tmp=0,result=0;
    for(int i=0;i<4;i++){
        int x,y;
        cin>>x>>y;
        tmp+=y-x;
        result=max(result,tmp);
    }
    cout<<result;
    return 0;
}