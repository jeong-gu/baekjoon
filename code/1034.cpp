#include <bits/stdc++.h>
using namespace std;
int arr[51];
vector<int> tr;
vector<int> party[51];
int Find(int a){
    if(a==arr[a]) return a;
    return arr[a]=Find(arr[a]);
}
bool isUnion(int a,int b){
    return Find(a)==Find(b);
}
void Union(int a,int b){
    int x=Find(a);
    int y=Find(b);
    if(x==y) return;
    if(x<y) arr[y]=x;
    else arr[x]=y;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    int tnum; cin>>tnum;
    int cnt=m;
    for(int i=0;i<tnum;i++){
        int a; cin>>a;
        tr.push_back(a);
    }
    for(int i=0;i<m;i++){
        int sz; cin>>sz;
        for(int j=0;j<sz;j++){
            int x; cin>>x;
            party[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++) arr[i]=i;
    for(int i=0;i<m;i++){
        int first=party[i].front();
        for(auto x:party[i]){
            Union(first,x);
        }
    }
    for(int i=0;i<m;i++){
        bool swt=true;
        for(auto x:party[i]){
            if(!swt) break;
            for(auto y:tr){
                if(isUnion(x,y)){
                    swt=false;
                    break;
                }
            }
        }
        if(!swt) cnt--;
    }
    cout<<cnt;
    return 0;
}