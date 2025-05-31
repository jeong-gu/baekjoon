#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int Find(int a){
    if(a==arr[a]) return a;
    return arr[a]=Find(arr[a]);
}
void Union(int a,int b){
    int x=Find(a);
    int y=Find(b);
    if(x==y) return;
    if(x<y){
        arr[y]=x;
    }
    else{
        arr[x]=y;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int g,p; cin>>g>>p;
    for(int i=1;i<=g;i++){
        arr[i]=i;
    }
    int cnt=0;
    for(int i=0;i<p;i++){
        int x; cin>>x;
        int a=Find(x);
        if(a==0)break;
        Union(a,a-1);
        cnt++;
    }
    cout<<cnt;

    return 0;
}