#include <bits/stdc++.h>
using namespace std;
int essay[101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int ans=0;
    int n,a,b; cin>>n>>a>>b;
    for(int i=0;i<n;i++) cin>>essay[i];
    sort(essay,essay+n);
    for(int i=0;i<n;i++){
        int tm=0,cnt=0,j=0;
        if(i>0){
            for(j=0;j<n;j++){
                if(cnt==i) break;
                if(tm+a<=essay[j]){
                    cnt++;
                    tm+=a;
                }
            }   
        }
        for(int x=0;x<a;x++){
            int ttm=b*x+tm;
            int ccnt=cnt;
            for(int k=j;k<n;k++){
                if(ttm+(a-x)<=essay[k]){
                    ttm+=(a-x);
                    ccnt++;
                }
            }
            ans=max(ans,ccnt);
        }
    }
    cout<<ans;


    return 0;
}