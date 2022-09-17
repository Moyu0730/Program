#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;

int nq( int n ){
    int p[14], total = 0;
    for( int i = 0 ; i < n ; i++ ) p[i] = i; // First Permutation
    do{
        // Check Valid
        bool valid = true;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if( abs(p[i]-p[j]) == j - i ){ // One The Same Diagonal
                    valid = false;
                    break;
                }
        if(valid) total++;
    } while ( next_permutation(p, p+n) ); // Until No-Next
    return total;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for( int i = 1 ; i < 12 ; i++ ){
        printf("%d\n", nq(i));
    }
    return 0;
}