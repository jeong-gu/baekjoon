#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100001];
int solve(int st,int en){
    if(st==en){
        return 0;
    }
    if(st+1==en){
        return a[st];
    }
    int mid=(st+en)/2;
    int result=max(solve(st,mid),solve(mid,en));
    
    result=max(result,a[mid]);
    int height=a[mid];
    int l=mid,r=mid;
    while(st<l||en>r){
        if(r<en&&(st==l||a[l-1]<=a[r+1])){
            r++;
            if(a[r]<height){
                height=a[r];
            }
        }
        else{
            l--;
            if(a[l]<height){
                height=a[l];
            }
        }
        result=max(result,height*(r+1-l));
    }
    return result;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<solve(0,n);

    return 0;
}