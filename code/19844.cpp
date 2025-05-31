#include <bits/stdc++.h>
using namespace std;

vector<string> v;
string s;

int main(){
    getline(cin, s);
    string temp = "";
    for(int i=0; i<s.length(); i++){
        if(i==s.length()-1){
        	temp+=s[i];
            v.push_back(temp);
        } 
        if(s[i] == ' ' || s[i] == '-'){
            v.push_back(temp);
            temp = "";
        }
        else{
            temp += s[i];
        }
    }
    int ans = v.size();
    for(int i=0; i<v.size(); i++){
        string temp2 = v[i];
        int findIdx = temp2.find("'");
        if(findIdx >= 0){
            string begin = "";
            for(int j=0; j<findIdx; j++){
                begin += temp2[j];
            }
            if(begin == "c" || begin == "j" || begin == "n"
                || begin == "m" || begin == "t" || begin == "s" 
                || begin == "l" || begin == "d" || begin == "qu"){
                if(temp2[findIdx+1] == 'a' || temp2[findIdx+1] == 'e' || temp2[findIdx+1] == 'i' || temp2[findIdx+1] == 'o' || temp2[findIdx+1] == 'u' || temp2[findIdx+1] == 'h'){
                    ans++;
                }
            }
        }
    }
    cout << ans;
    
    return 0;
}