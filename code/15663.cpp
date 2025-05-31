#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
int isused[10];
int set1[10];
void func(int x){
    if(x==m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    int tmp=0;
    for(int i=0;i<n;i++){
        if(!isused[i]&&tmp!=set1[i]){
            arr[x]=set1[i];
            isused[i]=true;
            tmp=set1[i];
            func(x+1);
            isused[i]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;  
    for(int i=0;i<n;i++){
        cin>>set1[i];
    }
    sort(set1,set1+n);
    func(0);
    return 0;
}