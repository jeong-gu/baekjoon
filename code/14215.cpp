#include <bits/stdc++.h>    
using namespace std;
int main(){
    int a,b,c; cin>>a>>b>>c;
    int mx=max({a,b,c});
    int others=a+b+c-mx;
    while(others<=mx){
        mx--;
    }
    cout<<mx+others;
}