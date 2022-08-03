#include<iostream>
#include<cmath>
#define int long long
using namespace std;

int a, b, c, x, y;

signed main(){
    cin >> a >> b >> c;
    x = ( ( -1 * b ) + sqrt( b * b - 4 * a * c ) ) / ( 2 * a );
    y =( ( -1 * b ) - sqrt( b * b - 4 * a * c ) ) / ( 2 * a );
    cout << x << " " << y;
}
