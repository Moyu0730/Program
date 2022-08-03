#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, len, ans;
bool x, y;
string s;
vector<bool> str;
vector<int> stk;

signed main(){
    cin >> n >> s;
    len = s.size();
    str.resize(len);
    for( int i = 0 ; i < len ; i++ ){
        str[i] = ( s[i] >= 97 ? 0 : 1 );  // 1 for Caps
    }
    ans = 0;
    for( int i = 0 ; i < len ; i++ ){
        if( i == 0 ){
            if( n == 1 ) x = !str[i];
            else x = str[i];
            stk.emplace_back(str[i]);

            continue;
        }
        if( str[i] == x ){
            stk.emplace_back(str[i]);
            if( stk.size() % n == 0 ){
                x = !stk.back();
                ans = max( ans, (int)stk.size() );
            }
        }else{
            if( str[i] == str[i-1] and n != 1 and stk.size() == n ) continue;
            stk.clear();
            x = str[i];
            stk.emplace_back(str[i]);
        }
    }
    cout << ans << '\n';
}
