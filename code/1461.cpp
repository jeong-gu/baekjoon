#include <bits/stdc++.h>
using namespace std;
vector<int> vec1;
vector<int> vec2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    int mx=-1;
    while(n--){
        int a; cin>>a;
        if(a<0) vec1.push_back(abs(a));
        else vec2.push_back(a);
    }
    sort(vec1.rbegin(),vec1.rend());
    sort(vec2.rbegin(),vec2.rend());

    int res1=0, res2=0;
    int i=0;
    while(i<vec1.size()){
        int a=vec1[i];
        i+=m;
        mx=max(mx,a);
        res1+=2*a;
    }
    i=0;
    while(i<vec2.size()){
        int a=vec2[i];
        i+=m;
        mx=max(mx,a);
        res2+=2*a;
    }
    
    int res=res1+res2;
    cout<<res-mx;


    return 0;
}