#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int Tree[4*1000001];
void updateTree(int node,int st,int en,int idx,int diff){
    if(idx<st||idx>en) return;
    Tree[node]+=diff;
    if(st==en) return;

    int mid=(st+en)/2;
    updateTree(2*node,st,mid,idx,diff);
    updateTree(2*node+1,mid+1,en,idx,diff);
    Tree[node]=Tree[2*node]+Tree[2*node+1];
}
void query(int node,int st,int en,int a){
    if(st==en){
        updateTree(1,1,1000000,st,-1);
        cout<<st<<"\n";
        return;
    }
    int mid=(st+en)/2;
    if(Tree[2*node]>=a){
        query(2*node,st,mid,a);
    }
    else{
        query(2*node+1,mid+1,en,a-Tree[2*node]);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    while(n--){
        int m; cin>>m;
        if(m==1){//query
            int a; cin>>a;
            query(1,1,1000000,a);
        }
        else if(m==2){//update
            int a,b; cin>>a>>b;
            updateTree(1,1,1000000,a,b);
        }

    }


    return 0;
}