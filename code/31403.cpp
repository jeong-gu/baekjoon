#include <bits/stdc++.h>
using namespace std;
int func(string str){
    int result=0;
    for(int i=0;str[i]!='\0';i++){
        result*=10;
        result+=(str[i]-'0');
    }
    return result;
}
int main(){
    string str1,str2,str3;
    cin>>str1>>str2>>str3;

    int result1;
    result1=func(str1)+func(str2)-func(str3);
    int result2;
    result2=func(str1+str2)-func(str3);

    cout<<result1<<"\n"<<result2;
}