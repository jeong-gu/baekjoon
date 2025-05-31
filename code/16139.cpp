#include <bits/stdc++.h>
using namespace std;
int d[26][200001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    for(int i=0;i<26;i++){
        char c=i+'a';
        if(str[0]==c){
            d[i][0]++;
        }
        for(int j=1;j<str.length();j++){
            d[i][j]=d[i][j-1];
            if(str[j]==c){
                d[i][j]++;
            }
        }
    }
    int t; cin>>t;
    while(t--){
        char c; cin>>c;
        int l,r; cin>>l>>r;
        if(l==0){
            cout<<d[c-'a'][r]<<"\n";
        }
        else{
            cout<<d[c-'a'][r]-d[c-'a'][l-1]<<"\n";
        }
    }


    return 0;
}
