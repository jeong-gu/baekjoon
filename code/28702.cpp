#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int result;
    for(int i=0;i<3;i++){
        string tmp;
        cin>>tmp;
        if(tmp[0]>='0'&&tmp[0]<='9'){
            int itmp=stoi(tmp);
            result=itmp+(3-i);
        }        
    }
    if(result%15==0){
        cout<<"FizzBuzz\n";
    }
    else if(result%5==0){
        cout<<"Buzz\n";
    }
    else if(result%3==0){
        cout<<"Fizz\n";
    }
    else{
        cout<<result<<"\n";
    }
    return 0;
}