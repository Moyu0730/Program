#include<iostream>
#define int long long
using namespace std;

int x, y, z;

signed main(){
    cin >> x >> y;
    while( y != 0 ){
        z = y;
        y = x%y;
        x = z;
    }
    cout << x;
}
