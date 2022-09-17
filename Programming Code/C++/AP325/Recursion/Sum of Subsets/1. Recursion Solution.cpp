#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 1e8 + 50;
int arr[26], p, n, best;

int func( int i, int ctn ){
    if( i > n-1 or ctn > p ) return ctn;

    if( func(i+1, ctn + arr[i]) <= p ) best = max(best, ctn + arr[i]);
    if( func(i+1, ctn) <= p ) best = max(best, ctn);
    
    return ctn;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> p;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];
    func(0, 0);
    cout << best;
}