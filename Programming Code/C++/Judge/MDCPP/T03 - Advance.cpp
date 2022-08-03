#include<iostream>
#include<vector>
#include<numeric>
#define int long long
using namespace std;

const int MAXN = 1e5 + 50;
int n, a, f, s, z, i, gcf, t;
vector<int> st;
int ans[MAXN];
int arr[MAXN];

bool cop( int x, int y ){
    while( y != 0 ){
        z = y;
        y = x%y;
        x = z;
    }
    if( x == 1 ) return true;
    else return false;
}

int gf( int x, int y ){
    return ( f * s ) / gcd(f, s);
}

signed main(){
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> a;
        st.push_back(a);
    }

    while( st.size() > 1 ){
        st.front();
    }

    for( int j = 1 ; j <= i ; j++ ){
        cout << ans[j] << " ";
    }
}
