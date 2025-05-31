#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,cnt=0;
    cin>>n>>k;
    int arr[2][7]={0,};
    while(n--){
        int s,y;
        cin>>s>>y;
        arr[s][y]++;
    }
    for(int i=1;i<=6;i++){
        for(int j=0;j<2;j++){
            if(arr[j][i]%k==0){
                cnt+=arr[j][i]/k;
            }
            else{
                cnt+=arr[j][i]/k+1;
            }
        }
    }
    cout<<cnt;
    return 0;
}