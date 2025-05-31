#include <bits/stdc++.h>
using namespace std;
pair<int,int> tree[27];
void pre(int node){
    if(node<0) return;
    cout<<char(node+'A');
    pre(tree[node].first);
    pre(tree[node].second);
}
void in(int node){
    if(node<0) return;
    in(tree[node].first);
    cout<<char(node+'A');
    in(tree[node].second);
}
void post(int node){
    if(node<0) return;
    post(tree[node].first);
    post(tree[node].second);
    cout<<char(node+'A');
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        char a[3]; 
        for(int i=0;i<3;i++){
            cin>>a[i];
            a[i]-='A';
        }
        tree[a[0]]={int(a[1]),int(a[2])};
    }
    pre(0);
    cout<<"\n";
    in(0);
    cout<<"\n";
    post(0);

    return 0;
}