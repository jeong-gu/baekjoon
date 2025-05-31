#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b;
    cin>>a>>b;
    int x=1;
    int t;
    while(1){
        x++;
        if((a+b)%x!=0) continue;
        t=(a+b)/x;
        if(!(x>2&&t>2))continue;
        if((x-2)*(t-2)==b){
            break;
        }
    }
    cout<<t<<" "<<x;
    return 0;
}