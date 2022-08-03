#include<iostream>
#define int long long
using namespace std;

const int MAXN = 1e5 + 50;
int arr[MAXN];
int a, b, c, n, z, t, p, e, pos, ti, now;

signed main(){
    cin >> a >> b >> c >> n;
    for( int i = 0 ; i < n ; i++ ){
      	cin >> z;
        arr[z] = 1;
    }
    e = 1000;
    while( cin >> t >> p ){
        if( t == 1 ){
            for( int i = 1 ; i <= p ; i++ ){
                if( arr[pos] == 1 ) e += 50;
                if( e < a ){
                    ti += 10;
                    e += 50;
                }else{
                    ti += 1;
                    e -= a;
                }
                pos += 1;
            }
        }else if( t == 2 ){
            for( int i = 1 ; i <= p ; i++ ){
                if( arr[pos] == 1 ) e += 50;
              	ti += 1;
                e += b;
                pos += 1;
            }
        }else{
            for( int i = 1 ; i <= p ; i++ ){
                if( arr[pos] == 1 ) e += 50;
                ti += 1;
                e += c;
                pos += 1;
            }
        }
    }
  	cout << ti;
}
