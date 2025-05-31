#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int mn=INT_MAX;
    for(int i=0;i<n;i++){
        int idx=lower_bound(a,a+n,-a[i])-a;
        for(int j=-1;j<=1;j++){
            if(idx+j<0||idx+j>=n||idx+j==i) continue;
            int tmp=a[i]+a[idx+j];
            if(abs(mn)>abs(tmp)){
                mn=tmp;
            }
        }
    }
    cout<<mn;
    return 0;
}