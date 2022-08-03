#include<iostream>
#include<queue>
#define int long long
using namespace std;

int f( int n, int k ){
    if( n == 1 ) return 1;
    if( k <= (n+1) / 2 ){
        if( 2 * k > n ) return ( 2 * k ) % n;
        else return 2 * k;
    }
    int temp = f( n/2, k-(n+1)/2 );
    if( n % 2 == 1 ) return 2 * temp + 1;
    return 2 * temp - 1;
}

signed main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
	cin >> q;
	for( int i = 0 ; i < q ; i++ ){
        int n, k;
        cin >> n >> k;
        cout << f(n, k) << '\n';
	}
}

/*
4
7 1
7 3
2 2
1337 1313
*/
