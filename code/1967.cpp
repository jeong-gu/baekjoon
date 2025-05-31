#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> vec[10001];
bool visited[10001];
int mxVal=-1;
int mxIdx=0;
void dfs(int idx,int val){
    visited[idx]=true;
    if(mxVal<val){
        mxVal=val;
        mxIdx=idx;
    }

    for(int i=0;i<vec[idx].size();i++){
        if(visited[vec[idx][i].first]) continue;
        dfs(vec[idx][i].first,vec[idx][i].second+val);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b,c; cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    dfs(1,0);
    mxVal=-1;
    fill(visited,visited+10001,false);
    dfs(mxIdx,0);
    cout<<mxVal;

    return 0;
}