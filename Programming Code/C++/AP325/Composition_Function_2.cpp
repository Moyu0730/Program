#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<stdlib.h>
using namespace std;

// const int MAXN;
string s;
int ans;

int func(){
    cin >> s;
    if( s == "f" ){
        ans = 2 * func() - 3;
    }else if( s == "g" ){
        ans = func() * 2 + func() - 7;
    }else if( s == "h" ){
        ans = func() * 3 - func() * 2 + func();
    }else{
        return stoi(s); // s for convert string to int
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << func();
}