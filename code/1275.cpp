#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q; 
ll arr[100001];
ll tree[4*100001];
void update(int node,int st,int en,int idx,ll val){
    if(idx<st||idx>en) return;
    if(st==en) {
        tree[node]=val;
        return;
    }
    int mid=(st+en)/2;
    update(2*node,st,mid,idx,val);
    update(2*node+1,mid+1,en,idx,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(int node,int st,int en,int l,int r){
    if(en<l||st>r) return 0;
    if(l<=st&&r>=en) return tree[node];

    int mid=(st+en)/2;
    ll lresult=query(2*node,st,mid,l,r);
    ll rresult=query(2*node+1,mid+1,en,l,r);
    return lresult+rresult;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }   
    for(int i=1;i<=n;i++){
        update(1,1,n,i,arr[i]);
    }
    for(int i=1;i<=q;i++){
        int x,y,a,b; cin>>x>>y>>a>>b;
        if(x>y) swap(x,y);
        cout<<query(1,1,n,x,y)<<"\n";
        update(1,1,n,a,b);
    }
    return 0;
}