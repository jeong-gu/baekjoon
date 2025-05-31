#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        list<char> list;
        auto cursor=list.end();
        for(int i=0;i<str.length();i++){
            char c=str[i];
            if(c=='<'){
                if(!list.empty()&&
                cursor!=list.begin()){
                    cursor--;
                }
            }
            else if(c=='>'){
                if(!list.empty()&&
                cursor!=list.end()){
                    cursor++;
                }
            }
            else if(c=='-'){
                if(cursor!=list.begin()) {
                    cursor=list.erase(--cursor);
                }
            }
            else{
                list.insert(cursor,c);
            }
        }
        for(auto i: list){
            cout<<i;
        }
        cout<<"\n";
    }
    return 0;
}