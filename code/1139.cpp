#include <bits/stdc++.h>
using namespace std;
int n;
double d[17];
double dp[(1<<16)-1];
double getS(double a,double b,double c){
    vector<double> vec;
    vec.push_back(a); vec.push_back(b);vec.push_back(c);
    sort(vec.begin(),vec.end());
    if(vec[0]+vec[1]>=vec[2]){
        double p=(a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    else{
        return -1;
    }
}
double func(int bm){
    double& ret=dp[bm];
    if(ret>0){
        return ret;
    }
    vector<int> vec;
    for(int i=0;i<n;i++){
        if((bm&(1<<i))==0){
            vec.push_back(i);
        }
    }
    if(vec.size()<3) return ret=0;

    int r=vec.size();
    for(int i=0;i<r-2;i++){
        for(int j=i+1;j<r-1;j++){
            for(int k=j+1;k<r;k++){
                int nxt=bm|(1<<vec[i])|(1<<vec[j])|(1<<vec[k]);
                double S=getS(d[vec[i]+1],d[vec[j]+1],d[vec[k]+1]);
                if(S==-1) continue;
                double p=S+func(nxt);
                ret=max(ret,p);
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    printf("%.9lf",func(0));
    return 0;
}