#include <bits/stdc++.h>
using namespace std;
int d[10];
int a[200001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int st,en,cnt;
    st=en=0;
    d[a[st]]++;    
    cnt=1;
    int ans=0;
    while(st<=en&&en<n){
        if(cnt<=2){
            ans=max(ans,en-st+1);   
            en++;
            if(d[a[en]]==0) cnt++;
            d[a[en]]++;
        }
        else{
            d[a[st]]--;
            if(d[a[st]]==0) cnt--;
            st++;
        }
    }
    cout<<ans;

    return 0;
}