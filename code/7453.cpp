#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll A[4001];
ll B[4001];
ll C[4001];
ll D[4001];
ll E[4001*4001];
ll F[4001*4001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    ll k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            E[k]=A[i]+B[j];
            F[k]=C[i]+D[j];
            k++;
        }
    }
    sort(F,F+n*n);
    ll cnt=0;
    for(int i=0;i<n*n;i++){
        cnt+=upper_bound(F,F+n*n,-E[i])-lower_bound(F,F+n*n,-E[i]);
    }
    cout<<cnt;
    return 0;
}