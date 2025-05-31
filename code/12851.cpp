#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int cnt[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    if(n==k){
        cout<<0<<"\n"<<1;
        return 0;
    }
    fill(arr,arr+100001,INT_MAX);
    queue<int> q;
    q.push(n);
    arr[n]=0;
    cnt[n]=1;
    while(!q.empty()){
        int cur=q.front(); q.pop();
        int nxt[3];
        nxt[0]=cur+1;
        nxt[1]=cur-1;
        nxt[2]=2*cur;
        for(auto x:nxt){
            if(x<0||x>100000) continue;
            if(arr[x]!=INT_MAX){
                if(arr[x]==arr[cur]+1){
                    cnt[x]+=cnt[cur];
                }
            }
            else{
                q.push(x);
                cnt[x]=cnt[cur];
                arr[x]=arr[cur]+1;
            }
        }
    }
    cout<<arr[k]<<"\n"<<cnt[k];
    return 0;
}