#include <bits/stdc++.h>
using namespace std;
int arr[200001];
vector<int> vec[200001];
bool cmp(int a,int b){
    return a>b;
}
int Find(int a){
    if(arr[a]==a) return a;
    return arr[a]=Find(arr[a]);    
}
void Union(int a,int b){
    int aa=Find(a);
    int bb=Find(b);
    if(aa==bb) return;
    if(aa<bb){
        arr[bb]=aa;
        for(auto x:vec[bb]){
            vec[aa].push_back(x);
        }
        sort(vec[aa].begin(),vec[aa].end(),cmp);
        while(vec[aa].size()>20) vec[aa].pop_back();
    }
    else{
        arr[aa]=bb;
        for(auto x:vec[aa]){
            vec[bb].push_back(x);
        }
        sort(vec[bb].begin(),vec[bb].end(),cmp);
        while(vec[bb].size()>20) vec[bb].pop_back();
    }
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        arr[i]=i;
        vec[i].push_back(i);
    }
    while(q--){
        int swt; cin>>swt;
        if(swt==1){
            int a,b; cin>>a>>b;
            Union(a,b);
        }
        else if(swt==2){
            int x,k; cin>>x>>k;
            int xx=Find(x);
            if(vec[xx].size()<k) cout<<"-1\n";
            else{
                cout<<vec[xx][k-1]<<"\n";
            }
        }
    }

    return 0;
}