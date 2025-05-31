#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
ll a[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll cnt=0,maxval=-(1LL<<62)-1,maxcnt=0;
    for(int i=0;i<n;i++){
        if(i==0||a[i]==a[i-1]) cnt++;
        else{
            if(cnt>maxcnt){
                maxval=a[i-1];
                maxcnt=cnt;
            }
            cnt=1;
        }
    }
    if(cnt>maxcnt) maxval=a[n-1];
    cout<<maxval;
    return 0;
}