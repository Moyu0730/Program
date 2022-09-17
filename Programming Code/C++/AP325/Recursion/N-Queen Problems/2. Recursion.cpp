#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;

// k is current row, p[] are column indexes of previous rows
int nq( int n, int k, int p[] ){
    if( k >= n ) return 1; // No more rows, successful
    int total = 0;
    bool valid[n];
    for( int i = 0 ; i < n ; i++ ) valid[i] = true;
    // Mark positions attached by (j, p[j])
    for( int j = 0 ; j < k ; j++ ){
        valid[p[j]] = false;
        int i = k - j + p[j];
        if( i < n ) valid[i] = false;
        i = p[j] - ( k - j );
        if( i >= 0 ) valid[i] == false;
    }
    for( int i = 0 ; i < n ; i++ ){ // Try each column
        if( valid[i] ){
            p[k] = i;
            total += nq(n, k+1, p);
        }
    }
    return total;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int p[15];
    for( int i = 0 ; i < 12 ; i++ ){
        printf("%d\n", nq(i, 0, p));
    }
    return 0;
}#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;

// k is current row, p[] are column indexes of previous rows
int nq( int n, int k, int p[] ){
    if( k >= n ) return 1; // No more rows, successful
    int total = 0;
    for( int i = 0 ; i < n ; i++ ){ // Try each column
        // Check Valid
        bool valid = true;
        for( int j = 0 ; j < k ; j++ ){
            if( p[j] == i || abs( i - p[j] ) == k - j ){
                valid = false;
                break;
            }
        }
        if(!valid) continue;        
        p[k] = i;
        total += nq(n, k+1, p);
    }   
    return total;

}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int p[15];
    for( int i = 0 ; i < 12 ; i++ ){
        printf("%d\n", nq(i, 0, p));
    }
    return 0;
}