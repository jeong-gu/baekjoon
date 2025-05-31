#include <bits/stdc++.h>
using namespace std;
int n;
int arr[2][1000001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp<0){
            arr[0][-tmp]++;
        }
        else{
            arr[1][tmp]++;
        }
    }
    for(int x=0;x<2;x++){
        if(x==0){
            for(int i=1000000;i>0;i--){
                    for(int j=0;j<arr[0][i];j++){
                        cout<<-i<<"\n";
                    }
            }
        }
        else{
            for(int i=0;i<=1000000;i++){
                    for(int j=0;j<arr[1][i];j++){
                        cout<<i<<"\n";
                    }
            }
        }
    }
    return 0;
}