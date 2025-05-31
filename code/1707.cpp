#include <bits/stdc++.h>
using namespace std;
int visited[20001];
vector<int> vec[20001];
void func(){
    int v,e; cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b; cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    for(int i=1;i<=v;i++){
        queue<int> q;
        if(visited[i]==0){
            visited[i]=1;
        }
        q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto c:vec[x]){
                if(visited[c]!=0){
                    if(visited[x]==visited[c]){
                        cout<<"NO\n";
                        return;    
                    }
                    continue;
                }
                q.push(c);
                if(visited[x]==1) visited[c]=2;
                else if(visited[x]==2) visited[c]=1;
            }
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<20001;i++){
            vec[i].clear();
        }
        fill(visited,visited+20001,0);
        func();
    }


    return 0;
}