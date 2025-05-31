#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z'){
            cout<<char(str[i]-'A'+'a');
        }
        else{
            cout<<char(str[i]-'a'+'A');
        }
    }


    return 0;
}