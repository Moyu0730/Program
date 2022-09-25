#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;

int jump_search( int a[], int n, int x ){
    if( a[0] >= x ) return 0; // Check the first 
    
    /*
     * if( a[0] >= x ) return x;
     *
     * Above is to deal with the situation that you want to find the maxnum value lower than x, but x is lower than a[0] 
     * It will return itself;
     */
    
    int pos = 0;
    for( int jump = n / 2 ; jump > 0 ; jump /= 2 ){
        while( pos + jump < n && a[pos + jump] < x ){
            pos += jump;
        }
    }
    return pos + 1; // return pos + 1 for the minumn data higher than x, return pos for the maxinum data lower than x
}

signed main(){
    opt;
    srand( time(NULL) );
    int p[10], n = 10;
    for( int i = 0 ; i < n ; i++ ) p[i] = rand() % 100;
    sort(p, p+n);
    for( int i = 0 ; i < n ; i++ ) cout << p[i] << " ";
    cout << '\n';

    cout << "Search " << p[7] << " => Return " << p[jump_search(p, n-1, p[7])] << '\n';
    int t = rand() % 100;
    cout << "Search " << t << " => Return " << p[jump_search(p, n-1, t)] << '\n';
}