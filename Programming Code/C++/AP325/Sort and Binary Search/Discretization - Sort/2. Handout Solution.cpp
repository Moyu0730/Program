#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define N 100010

int distinct(int from[], int to[], int n) {
    if( n < 1 ) return 0;
    vector<int> v ( from, from + n ); // Copy from[] to v
    sort( v.begin(), v.end() );
    to[0] = v[0];
    int num = 1; // Number of distinct number
    for ( int i = 1 ; i < n ; i++ )
        if ( v[i] != v[i-1] ) // Distinct
            to[num++] = v[i];
    return num;
}

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;

signed main(){
    opt;
    int a[N], b[N],n, k;

    // Input data
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    
    // Sort distinct number to b
    k = distinct( a, b, n );
    
    // Replace number with its rank
    for( int i = 0 ; i < n ; i++ ) a[i] = lower_bound(b, b+k,a[i]) - b; // Always found
    
    // Output
    for( int i = 0 ; i < n ; i++ ) cout << lower_bound(b, b+k,a[i]) - b; << " ";
    cout << '\n';
    return 0;
}