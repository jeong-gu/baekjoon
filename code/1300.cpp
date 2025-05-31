#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    int st=1;
    int en=k;
    int answer=0;
    while(1){
        if(st>en) break;

        int cnt=0;
        int mid=(st+en)/2;
        for(int i=1;i<=n;i++){
            cnt+=min(n,mid/i);
        }
        if(cnt>=k){
            answer=mid;
            en=mid-1;
        }
        else if(cnt<k){
            st=mid+1;
        }
    }
    cout<<answer;
}