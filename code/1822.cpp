#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> c;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        a.push_back(tmp);        
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        b.push_back(tmp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(!binary_search(b.begin(),b.end(),a[i])){
            c.push_back(a[i]);
        }
    }
    cout<<c.size()<<"\n";
    for(auto i:c){
        cout<<i<<" ";
    }
    return 0;
}