#include <bits/stdc++.h>
using namespace std;
deque<int> deq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n; //n<=3*10^5
    double sum=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
        deq.push_back(tmp);
    }
    sort(deq.begin(),deq.end());
    int x=round(double(n)*0.15);
    for(int i=0;i<x;i++){
        sum-=deq.front();
        deq.pop_front();
        sum-=deq.back();
        deq.pop_back();
    }
    if(deq.empty()){cout<<0;}
    else cout<<round(sum/deq.size());
    return 0;
}