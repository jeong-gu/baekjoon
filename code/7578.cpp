#include <bits/stdc++.h>
using namespace std;
int A[500001];
int B[1000001];
int Tree[500001*4];
void updateTree(int node,int st,int en,int idx){
    if(idx<st||idx>en) return;
    Tree[node]=1;
    if(st==en) {
        return;
    }
    int mid=(st+en)/2;
    updateTree(2*node,st,mid,idx);
    updateTree(2*node+1,mid+1,en,idx);
    Tree[node]=Tree[2*node]+Tree[2*node+1];
}
int query(int node,int st,int en,int larea,int rarea){
    if(larea>en||rarea<st) return 0;
    if(st>=larea&&en<=rarea) return Tree[node];

    int mid=(st+en)/2;
    int lresult=query(2*node,st,mid,larea,rarea);
    int rresult=query(2*node+1,mid+1,en,larea,rarea);
    return lresult+rresult;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        B[x]=i;
    }
    long long result=0;
    for(int i=1;i<=n;i++){
        result+=query(1,1,n,B[A[i]]+1,n);
        updateTree(1,1,n,B[A[i]]);
    }
    cout<<result;
    return 0;
}