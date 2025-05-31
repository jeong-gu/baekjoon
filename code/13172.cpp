#include <bits/stdc++.h>
using namespace std;
long long int X=1000000007;
long long int tmpPow(long long int x,long long int n){
    if(n>1){
        long long int half=tmpPow(x,n/2);
        long long int result=(half*half)%X;
        if(n%2==1){
            result*=x;
            result%=X;
        }
        return result;
    }
    return x;
}
long long int func(long long int b,long long int a){
    int bInverse=tmpPow(b,X-2);
    cout<<bInverse<<"\n";
    int result;
    result=(a*bInverse)%X;
    return result;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    long long int result=0;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,s; cin>>n>>s;
        result+=func(n,s);
        result%X;
    }
    cout<<result%X;

    return 0;
}