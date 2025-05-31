#include <bits/stdc++.h>
using namespace std;
int arr1[26];
int arr2[26];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; 
    cin>>str;
    for(auto i: str){
        arr1[i-'a']++;
    }
    cin>>str;
    for(auto i: str){
        arr2[i-'a']++;
    }
    int cnt=0;
    for(int i=0;i<26;i++){
        cnt+=abs(arr1[i]-arr2[i]);
    }
    cout<<cnt;
    return 0;
}