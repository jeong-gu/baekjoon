#include <bits/stdc++.h>    
using namespace std;
string a;
string b;
int d[1001][1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b;
    for(int i=0;i<=a.length()-1;i++){
        for(int j=0;j<=b.length()-1;j++){
            if(a[i]==b[j]){
                d[i+1][j+1]=d[i][j]+1;
            }
            else{
                d[i+1][j+1]=max(d[i][j+1],d[i+1][j]);
            }
        }
    }
    cout<<d[a.length()][b.length()];


    return 0;
}