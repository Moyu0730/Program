#include<iostream>
#include<set>
#define int long long
using namespace std;

const int MAXN = 500;
int te[MAXN];
int st[MAXN];
int ans[MAXN];

int n, mi, k;

signed main(){
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> te[i];
    }
    for( int i = 1 ; i <= n ; i++ ){
        cin >> st[i];
    }
    for( int i = 1 ; i <= n ; i++ ){
        mi = 1e10;
        for( int j = 1 ; j <= n ; j++ ){
            if( te[i] == st[j] ){
                mi = min( mi, abs(i-j) );
                k = 1;
            }
        }
        if( k != 1 ) cout << -1 << " ";
        else cout << mi << " ";
        k = 0;
    }
}
