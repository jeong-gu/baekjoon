#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> vec;
int dp[16][1<<16];
int func(int now,int state){
    int &ret=dp[now][state];
    if(ret>0){
        return ret;
    }
    if(state==(1<<n)-1){
        return ret;
    }

    for(int i=0;i<n;i++){
        if(state&(1<<i))  continue;
        if(vec[i].front()!=vec[now].back()) continue;
        int p=func(i,state|(1<<i))+vec[i].length();
        ret=max(ret,p);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        string str; cin>>str;
        vec.push_back(str);
    }
    int result=0;
    for(int i=0;i<n;i++){
        int p=func(i,1<<i)+vec[i].length();
        result=max(result,p);
    }
    cout<<result;

    return 0;
}