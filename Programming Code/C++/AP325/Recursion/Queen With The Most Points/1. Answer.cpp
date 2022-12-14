#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int arr[MAXN][MAXN];

// k is current row, p[] are column indexes of previous rows
int nq( int n, int k, int p[] ){
    if( k >= n ){
        int res = 0;
        for( int i = 0 ; i < k ; i++ ){
            res += arr[p[i]][i];
        }
        return res; // No more rows, successful
    }
    int Max = -1;
    bool valid[n];
    for( int i = 0 ; i < n+1 ; i++ ) valid[i] = true;
    // Mark positions attached by (j, p[j])
    for( int j = 0 ; j < k ; j++ ){
        if( p[j] == n ) continue;
        valid[p[j]] = false; // Delete straight
        int i = k - j + p[j]; 
        if( i < n ) valid[i] = false; // Delete bottom right slash
        i = p[j] - ( k - j );   
        if( i >= 0 ) valid[i] = false; // Delete bottom left slash
    }
    for( int i = 0 ; i < n+1 ; i++ ){ // Try each column
        if( valid[i] ){
            p[k] = i;
            Max = max(Max, nq(n, k+1, p));
        }
    }
    return Max;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, p[15];
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            cin >> arr[i][j];
        }
    }
    cout << nq(n, 0, p) << '\n';
    return 0;
}