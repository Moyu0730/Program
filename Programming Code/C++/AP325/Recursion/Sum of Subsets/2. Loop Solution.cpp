#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 26 + 5;
const int Mod = 10009;
long long arr[MAXN];

signed main(){
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, ans = 0;
    long long ctn;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];
    for( int i = 1 ; i < (1<<n) ; i++ ){ // Brute force all possibilities
        ctn = 1;
        for( int j = 0 ; j < n ; j++ ){ // Check j-th bit
            if( i & (1<<j) ){ // Check if j-th bit is true
                ctn = ( ctn * arr[j] ) % Mod; // If j-th is true, remember the answer after % Mod
            }
        }
        if( ctn == 1 ) ans++;
    }
    cout << ans;
}