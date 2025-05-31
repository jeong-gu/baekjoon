#include <bits/stdc++.h>
using namespace std;
struct adj{
    int cost,x,y;
    bool operator<(adj&other){
        return cost<other.cost;
    }
};
int arr[100001];
int Find(int x){
    if(arr[x]==x) return x;
    return arr[x]=Find(arr[x]);
}
bool Union(int a,int b){
    int x=Find(a);
    int y=Find(b);
    if(x==y) return false;
    if(x>y) arr[x]=y;
    else arr[y]=x;
    return true;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    vector<adj> vec;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        vec.push_back({c,a,b});
    }
    sort(vec.begin(),vec.end());
    vector<int> ans;
    for(auto v:vec){
        if(Union(v.x,v.y)){
            ans.push_back(v.cost);
        }
    }
    int res=0;
    for(auto c:ans){
        res+=c;
    }
    cout<<res;
    return 0;
}
