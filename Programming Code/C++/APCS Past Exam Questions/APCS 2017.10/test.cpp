#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k; cin >> k;
    string s, ans; cin >> s;
    int cal;
    int len = s.size();
    for( int i = 0 ; i < len ; i++ ) (int)s[i] < 91 ? s[i] = 'B' : s[i] = 'S';
    for( int i = 1 ; i < len ; i++ ){ // B for 0, S for 1
        while( s[i] != s[i-1] || i == 0 ){
            cal++;
            ans += itoa(a)
        }
    }
}