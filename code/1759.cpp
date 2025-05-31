#include <bits/stdc++.h>
using namespace std;
int l,c;
char box[20];
char arr[20];
bool isvowels(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
        return true;
    }
    return false;
}
void func(int x,int min,int con,bool vowel){
    if(x==l){
        if(!vowel) return;
        if(con<2) return;
        for(int i=0;i<l;i++){
            cout<<arr[i];
        }
        cout<<"\n";
        return;
    }for(int i=min;i<c;i++){
        arr[x]=box[i];
        if(isvowels(box[i])) func(x+1,i+1,con,true);
        else func(x+1,i+1,con+1,vowel);
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>l>>c;
    for(int i=0;i<c;i++){
        cin>>box[i];
    }
    sort(box,box+c);
    func(0,0,0,false);
    return 0;
}