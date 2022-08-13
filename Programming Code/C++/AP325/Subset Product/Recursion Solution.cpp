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
int ans, n;

void soluiton( int i, int ctn ){
    if( i >= n ){ // Terminal Condition
        if( ctn == 1 ) ans++;
        return;
    }

    soluiton(i+1, (ctn*arr[i]) % Mod ); // Select arr[i]
    soluiton(i+1, ctn); // Discard arr[i] 
    return;
}

signed main(){
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];
    soluiton(0, 1);
    cout << ans-1; // -1 for empty subset
}