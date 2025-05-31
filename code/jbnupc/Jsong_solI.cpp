#include <bits/stdc++.h>
using namespace std;
int a[100001];
int f[100001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>f[i];

    for(int i=0;i<n;i++){
        string str; cin>>str;
        if(str=="get"){
            int c; cin>>c;
            
        }
        else if(str=="set"){
            int c1,c2; cin>>c1>>c2;
            if(c1-1<0) continue;
            a[c1-1]=c2;
        }
    }



    return 0;
}