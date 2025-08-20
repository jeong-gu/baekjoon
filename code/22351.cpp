#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>str;
    
    int p=1;
    while(1){
        string f="";
        for(int i=0;i<p;i++){
            f+=str[i];
        }
        int fnum=0;
        for(int i=0;i<f.size();i++){
            fnum+=f[i]-'0';
            if(i+1==f.size()) break;
            fnum*=10;
        }
        bool swt=true;
        string ffnum=to_string(fnum);
        for(int i=f.size();i<str.size();i+=ffnum.size()){
            fnum++;
            ffnum=to_string(fnum);
            
            for(int j=0;j<ffnum.size();j++){
                if(str[i+j]!=ffnum[j]) {swt=false; break;}
            }

        }

        if(swt){
            string first="";
            string last="";
            for(int i=0;i<p;i++){
                first+=str[i];
            }
            for(int i=0;i<ffnum.size();i++){
                last+=str[str.size()-1-i];
            }
            reverse(last.begin(),last.end());

            cout<<first<<" "<<last;
            return 0;
        }
        p++;
    }



    return 0;
}