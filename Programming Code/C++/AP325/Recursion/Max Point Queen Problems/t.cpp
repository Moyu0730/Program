#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 1e4 + 50;
const int Mod = 1e9 + 7;
int ans = -1;
int arr[MAXN][MAXN];

int nq( int n ){
    int p[14], total = 0, result = -1;
    for( int i = 0 ; i < n ; i++ ) p[i] = i; // First Permutation
    do{
        // Check Valid
        total = 0;
        bool valid = true;
        for( int i = 0 ; i < n ; i++ ){
            for( int j = i+1 ; j < n ; j++ ){
                if( abs(p[i]-p[j]) == j - i ){ // One The Same Diagonal
                    valid = false;
                    break;
                }
            }
        }
        if(valid){
            for( int i = 0 ; i < n ; i++ ) total += arr[i][p[i]];
            result = max( result, total );
            cout << result << 
        }
    } while ( next_permutation(p, p+n) ); // Until No-Next
    return result;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < n ; j++ ) cin >> arr[i][j];
    
    for( int i = 1 ; i <= n ; i++ ){
        ans = max(ans, nq(i));
    }
    cout << ans;
    return 0;
}