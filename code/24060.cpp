#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,ans;
int arr[500001];
void merge(int st,int mid,int en){
    vector<int> vec;
    int i=st,j=mid+1;
    while(i<=mid&&j<=en){
        if(arr[i]<=arr[j]){
            vec.push_back(arr[i++]);
        }
        else{
            vec.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        vec.push_back(arr[i++]);
    }
    while(j<=en){
        vec.push_back(arr[j++]);
    }
    int t=st;
    for(auto x:vec){
        arr[t++]=x;
        cnt++;
        if(cnt==k){
            ans=x;
        }       
    }
}
void merge_sort(int st,int en){
    if(st<en){
        int mid=(st+en)/2;
        merge_sort(st,mid);
        merge_sort(mid+1,en);
        merge(st,mid,en);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(0,n-1);
    if(ans) cout<<ans;
    else cout<<"-1";    

    return 0;
}