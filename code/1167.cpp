#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> vec[100001];
bool visited[100001];
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
    for(int i=0;i<n;i++){
        int x; cin>>x;
        while(1){
            int a; cin>>a;
            if(a==-1) break;
            int b; cin>>b;
            vec[x].push_back({a,b});
        }
    }
    dfs(1,0);
    mxVal=-1;
    fill(visited,visited+100001,false);
    dfs(mxIdx,0);
    cout<<mxVal;
    
    return 0;
}