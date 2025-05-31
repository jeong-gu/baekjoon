#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==0&&b==0&&c==0) break;
        int mx=max({a,b,c});
        int others=a+b+c-mx;
        if(mx>=others) cout<<"Invalid\n";

        else if(a==b&&b==c) cout<<"Equilateral\n";
        else if(a==b||b==c||a==c) cout<<"Isosceles\n";
        else cout<<"Scalene\n";
        
    }
    return 0;
}