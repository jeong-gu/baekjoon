#include <bits/stdc++.h>
using namespace std;
int arr[1000001];

int Find(int x){
    if(x==arr[x]) return x;
    return arr[x]=Find(arr[x]);
}
bool isUnion(int a,int b){
    int X=Find(a);
    int Y=Find(b);
    return X==Y;
}
void Union(int a,int b){
    int X=Find(a);
    int Y=Find(b);
    if(X==Y) return;

    if(X<Y) arr[Y]=X;
    else arr[X]=Y;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int j=1;j<=n;j++){
        arr[j]=j;
    }
    for(int i=0;i<m;i++){
        int x,a,b; cin>>x>>a>>b;
        if(x==0){
            Union(a,b);      
        }
        else if(x==1){
            if(isUnion(a,b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}