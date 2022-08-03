#include<iostream>
#include<map>
#include<vector>
#include <cctype> // toupper
#define int long long
using namespace std;

string text;
string s;
string ans;
map<int, vector<string>> mp;
int n;
bool x;

signed main(){
    getline(cin , text);
    s = "";
    n = 0;
    ans = "";
    for( int i = 0 ; i < text.size() ; i++ ){
        if(  text[i] != ' ' ){
            if( text[i] >= 'A' && text[i] <= 'Z' )
                text[i]=text[i]+32;
            s += text[i];
            n++;
        }else{
            mp[n].emplace_back(s);
            s = "";
            n = 0;
        }
    }
    mp[n].emplace_back(s);
    x = 1;
    for( auto i:mp ){
        if( x ){
            i.second[0] = toupper(i.second[0]);
            x = 0;
        }
        ans += i.second;
        ans += " ";
    }
    cout << ans;
}
