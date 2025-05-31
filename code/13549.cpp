#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    fill(arr,arr+100001,INT_MAX);
    queue<int> q;
    q.push(n);
    arr[n]=0;
    while(!q.empty()){
        int cur=q.front(); q.pop();
        int nxt[3];
        nxt[0]=cur-1;
        nxt[1]=cur+1;
        nxt[2]=2*cur;
        for(auto x:nxt){
            if(x<0||x>100000) continue;
            if(x==2*cur&&arr[x]>arr[cur]){
                arr[x]=arr[cur];
                q.push(x);
            }
            else if(arr[x]>arr[cur]+1){
                arr[x]=arr[cur]+1;
                q.push(x);
            }
        }
    }
    cout<<arr[k];
    return 0;
}