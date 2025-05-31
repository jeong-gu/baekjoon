#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int d[1000001];
int Find(int x){
    if(x==arr[x]) return x;
    return arr[x]=Find(arr[x]);
}
void Union(int a,int b){
    int x=Find(a);
    int y=Find(b);
    if(x==y) return;
    if(x<y) {
        arr[y]=x;
        d[x]+=d[y];
        d[y]=0;
    }
    else{
        arr[x]=y;
        d[y]+=d[x];
        d[x]=0;
    }
}
int Query(int a){
    return d[Find(a)];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=1000000;i++){
        arr[i]=i;
        d[i]=1;
    }
    for(int i=0;i<n;i++){
        char c; cin>>c;
        if(c=='I'){
            int a,b; cin>>a>>b;
            Union(a,b);
        }
        else if(c=='Q'){
            int a; cin>>a;
            cout<<Query(a)<<"\n";
        }
    }
}