#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> vec;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    sort(vec.begin(),vec.end(),cmp);
    for(auto i:vec){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    
    return 0;
}
