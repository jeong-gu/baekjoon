#include <bits/stdc++.h>
using namespace std;
double dp[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    double a;double d;double k; cin>>a>>d>>k;

    double res=0; int i=0; dp[0]=1;
    double aa=a;
    while(d<100){
        res+=dp[i]*(d/100)*aa;

        dp[i+1]=dp[i]*((100-d)/100);

        d=d+d*(k/100);
        
        aa+=a;
        i++;
    }
    res+=dp[i]*(aa);
 
    printf("%.7lf",res);


    return 0;
}