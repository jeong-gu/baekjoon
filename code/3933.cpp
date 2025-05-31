#include <bits/stdc++.h>
using namespace std;
int d[32770][5];
void func(){
    for(int i=1;i*i<32770;i++){
        d[i*i][1]+=1;
        for(int j=i*i;j<32770;j++){
            for(int k=2;k<=4;k++){
                d[j][k]+=d[j-i*i][k-1];
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    func();
    while(1){
        int n; cin>>n;
        if(n==0) break;
        int result=0;
        for(int i=1;i<=4;i++){
            result+=d[n][i];
        }
        cout<<result<<"\n";
    }


    return 0;
}