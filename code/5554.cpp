#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n=4,sum=0,tmp;
    while(n--){
        cin>>tmp;
        sum+=tmp;
    }
    cout<<sum/60<<"\n"<<sum%60;
    return 0;
}