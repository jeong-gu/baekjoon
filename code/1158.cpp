#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    list<int> list;
    vector<int> vec;
    for(int i=0;i<n;i++){
        list.push_back(i+1);
    }
    auto index=list.begin();
    while(!list.empty()){
        for(int i=0;i<k-1;i++){
            index++;
            if(index==list.end()){
                index=list.begin();
            }
        }
        vec.push_back(*index);
        index=list.erase(index);
        if(index==list.end()) index=list.begin();
    }
    int pos=0;
    cout<<"<";
    for(auto i:vec){
        cout<<i;
        if(pos==vec.size()-1) break;
        cout<<", ";
        pos++;
    }
    cout<<">";
    return 0;
}