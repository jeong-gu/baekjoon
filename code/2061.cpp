#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    string k; int l; cin>>k>>l;
    for(int i=2;i<l;i++){
        int box=0;
        for(int j=0;j<k.length();j++){
            box=(box*10+(k[j]-'0'))%i;
        }
        if(box==0) {
            cout<<"BAD "<<i;
            return 0;
        }
    }
    cout<<"GOOD";

    return 0;
}