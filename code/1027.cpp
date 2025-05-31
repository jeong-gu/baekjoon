#include <bits/stdc++.h>
using namespace std;
int n;
int arr[51];
double func(int i,int x){
    int a=arr[x]-arr[i];
    int b=x-i;
    return a/b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        int left=i;
        int tmpnode=-1;
        int tmp=-1;
        while(1){
            if(--left<0) break;
            if(tmpnode==-1){
                tmpnode=left;
                tmp=arr[left];
                cnt++;
            }
            else if(tmp<arr[left]){
                int x=(i-tmpnode)*(i-left);
                if(tmp*x<arr[left]*x){
                    tmpnode=left;
                    tmp=arr[left];
                    cnt++;
                }
            }
        }
        int right=i;
        tmpnode=-1;
        tmp=-1;
        while(1){
            if(++right>=n) break;
            if(tmpnode==-1){
                tmpnode=right;
                tmp=arr[right];
                cnt++;
            }
            else if(tmp<arr[right]){
                int x=(tmpnode-i)*(right-i);
                if(tmp*x<arr[right]*x){
                    tmpnode=right;
                    tmp=arr[right];
                    cnt++;
                }
            }
        }
        res=max(res,cnt);
    }
    cout<<res;
    return 0;
}