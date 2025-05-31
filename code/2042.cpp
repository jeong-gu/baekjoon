#include <bits/stdc++.h>
using namespace std;
long long arr[1000001];
long long tree[4000004];
long long setTree(int node,int st,int en){
    if(st==en) return tree[node]=arr[st];

    int mid=(st+en)/2;
    long long lresult=setTree(2*node,st,mid);
    long long rresult=setTree(2*node+1,mid+1,en);

    return tree[node]=lresult+rresult;
}
void updateTree(int node,int st,int en,int idx,long long diff){
    if(idx<st||idx>en) return;
    tree[node]+=diff;
    if(st==en) return;

    int mid=(st+en)/2;
    updateTree(2*node,st,mid,idx,diff);
    updateTree(2*node+1,mid+1,en,idx,diff);
}
long long printTree(int node, int st,int en,int larea,int rarea){
    if(larea>en||rarea<st) return 0;
    if(larea<=st&&en<=rarea) return tree[node];
    
    int mid=(st+en)/2;
    long long lresult=printTree(2*node,st,mid,larea,rarea);
    long long rresult=printTree(2*node+1,mid+1,en,larea,rarea);

    return lresult+rresult;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    long long n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    setTree(1,1,n);
    for(int i=1;i<=m+k;i++){
        long long a,b,c; cin>>a>>b>>c;
        if(a==1){
            long long diff=c-arr[b];
            arr[b]+=diff;
            updateTree(1,1,n,b,diff);
        }
        if(a==2){
            cout<<printTree(1,1,n,b,c)<<"\n";
        }
    }

    return 0;
}
