#include <bits/stdc++.h>    
using namespace std;
long long int result=1;
//n! / r! * (n-r)!

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    int r=(m>n-m)?m:n-m;
    long long int ans=1;
    vector<int> v1;
    for(int i=r+1;i<=n;i++){
        v1.push_back(i);
    }   
    vector<int> v2; 
    for(int i=n-r;i>=1;i--){
        v2.push_back(i);
    }
    int i=0;
    if(v1.size()>v2.size()){
        for(;i<v2.size();i++){
            ans*=v1[i]/v2[i];
            i++;
        }
        for(int j=i+1;j<v1.size();j++){
            ans*=v1[j];
            j++;
        }
    }
    else{
        for(;i<v1.size();i++){
            ans*=v1[i]/v2[i];
            i++;
        }
        for(int j=i+1;j<v2.size();j++){
            ans/=v2[j];
            j++;
        }
    }
    cout<<ans;
    return 0;
}