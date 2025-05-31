#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,sum=0;
    cin>>n;
    ll ton_1=(n*(n-1)/2);
    while(n--){
        int input;
        cin>>input;
        sum+=input;
    }
    cout<<sum-ton_1;
    return 0;
}