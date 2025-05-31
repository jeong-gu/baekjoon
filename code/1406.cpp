#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int t;
    cin>>t;
    list<char> list;
    for(int i=0;i<str.length();i++){
        list.push_back(str[i]);
    }
    auto cursor=list.end();
    for(int i=0;i<t;i++){
        char c;
        cin>>c;
        if(c=='L'){
            if(cursor==list.begin()) continue;
            cursor--;
        }
        else if(c=='D'){
            if(cursor==list.end())continue;
            cursor++;
        }
        else if(c=='B'){
            if(cursor==list.begin()) continue;
            auto tmp=cursor;
            tmp--;
            list.erase(tmp);
        }
        else if(c=='P'){
            char x;
            cin>>x;
            list.insert(cursor,x);
        }
    }
    for(auto i:list){
        cout<<i;
    }
    return 0;
}