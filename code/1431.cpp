#include <bits/stdc++.h>
using namespace std;
vector<string> vec;
bool cmp(const string &a,const string &b){
    if(a.length()!=b.length()){
        return a.length()<b.length();
    }
    else{
        int asum=0,bsum=0;
        for(int i=0;i<a.length();i++){
            if(a[i]>='0'&&a[i]<='9') asum+=(a[i]-'0');
        }
        for(int i=0;i<b.length();i++){
            if(b[i]>='0'&&b[i]<='9') bsum+=(b[i]-'0');
        }
        if(asum!=bsum) return asum<=bsum;
        else return a<b;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string tmp;
    while(n--){
        cin>>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end(),cmp);
    for(auto i: vec){
        cout<<i<<"\n";
    }
    return 0;
}