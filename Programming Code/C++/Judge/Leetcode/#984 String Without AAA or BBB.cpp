#include<iostream>
using namespace std;

string ans = "";
int a, b;

signed main(){
    cin >> a >> b;
    while( a && b ){
        if( a > b ){
            ans += "aab";
            a--;
        }else if( b > a ){
            ans += "bba";
            b--;
        }else{
            ans += "ab";
        }
        a--;
        b--;
    }
    while( a-- > 0 ) ans += "a";
    while( b-- > 0 ) ans += "b";
    cout << ans;
}
