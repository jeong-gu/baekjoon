#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int tree[4*100001];
int setTree(int node,int st,int en){
    if(st==en) return tree[node]=arr[st];

    int mid=(st+en)/2;
    int lresult=setTree(2*node,st,mid);
    int rresult=setTree(2*node+1,mid+1,en);
    return tree[node]=lresult*rresult;
}
void updateTree(int node, int st, int en, int idx, int val) {
    if(st == en) {
        tree[node] = val;
        return;
    }
    
    int mid = (st + en) / 2;
    if(idx <= mid) updateTree(2 * node, st, mid, idx, val);
    else updateTree(2 * node + 1, mid + 1, en, idx, val);
    
    tree[node] = tree[2 * node] * tree[2 * node + 1];
}
int query(int node,int st,int en,int larea,int rarea){
    if(en<larea||st>rarea) return 1;
    if(st>=larea&&en<=rarea) return tree[node];

    int mid=(st+en)/2;
    int lresult=query(2*node,st,mid,larea,rarea);
    int rresult=query(2*node+1,mid+1,en,larea,rarea);
    return lresult*rresult;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; 
    while(cin>>n>>k){
        for(int i=1;i<=n;i++){
            int f; cin>>f;
            if(f>0)f=1;
            else if(f<0) f=-1;
            else f=0;
            arr[i]=f;
        }
        setTree(1,1,n);
        for(int i=1;i<=k;i++){
            char c; int x,y;
            cin>>c>>x>>y;
            if(c=='C'){//update
                if(y>0)y=1;
                else if(y<0) y=-1;
                else y=0;
                arr[x]=y;
                updateTree(1,1,n,x,y);
            }
            else if(c=='P'){//query
                int q=query(1,1,n,x,y);
                if(q>0){
                    cout<<"+";
                }
                else if(q<0){
                    cout<<"-";
                }
                else{
                    cout<<"0";
                }
            }
        }
        cout<<"\n";
    }

    return 0;
}