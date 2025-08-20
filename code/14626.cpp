#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    int idx=0;
    int res=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='*'){
            idx=i;
            continue;
        }
        if(i%2){
            res+=3*(str[i]-'0');
        }
        else{
            res+=(str[i]-'0');
        }
    }
    for(int i=0;i<10;i++){
        if(idx%2){
            if((res+3*i)%10==0){
                cout<<i; return 0;
            }
        }
        else{
            if((res+i)%10==0){
                cout<<i; return 0;
            }
        }
    }


    return 0;
}