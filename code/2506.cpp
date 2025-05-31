#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,input,tmp=0,result=0; cin>>n;
    while(n--){
        cin>>input;
        if(input){
            tmp++;
            result+=tmp;
        }
        else tmp=0;
    }
    cout<<result;
    return 0;
}