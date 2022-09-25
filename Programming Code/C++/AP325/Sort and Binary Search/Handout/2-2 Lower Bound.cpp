#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define N 5

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;

signed main(){
    opt;
    int p[N] = {5, 1, 8, 3, 9};
    int n = 5;
    sort(p, p+n);
    for( int i = 0; i < n ; i++ ) cout << p[i] << " ";
    cout << "\n";

    cout << "\nFor Array\n";
    for( int i = 0 ; i < N ; i++ ){
        int t = i * 3;
        // Search [first = p, last = p + n) to find the first >= t
        int ndx = lower_bound(p, p+n, t) - p;
        if( ndx < n ) cout << "The First >= " << t << " is at [" << ndx << "]" << '\n';
        else cout << "No one >= " << t << "\n"; // Return the last address if not found
    }

    // For Vector
    cout << "\nFor Vector\n";
    vector<int> v(p, p+n);
    for( int i = 0 ; i < N ; i++ ){
        int t = i * 3;
        int ndx = lower_bound(v.begin(), v.end(), t) - v.begin();
        if( ndx < n ) cout << "The First >= " << t << " is at [" << ndx << "]" << '\n';
        else cout << "No one >= " << t << "\n"; // Return the v.end() if not found
    }

    return 0;
}