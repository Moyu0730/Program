#include<iostream>
#include<set>
#define int long long
using namespace std;

const int MAXN = 1e8 + 50;
set<int> s;
int m, a, n, c, k;

signed main(){
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> a;
        s.insert(a);
    }

    k = 0;
    while( cin >> m ){
        if( k == 0 ) c += m;
        else c += m * 2;
        cout << c << '\n';
        k = 0;
        if( *s.find(c) == c ) k = 1;
    }
}
