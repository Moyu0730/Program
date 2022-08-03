#include<iostream>
#include<string>
#include<memory.h>
#define int long long
using namespace std;

const int MAXN = 5e6 + 50;
char ans[MAXN];
char t[MAXN];
int n, a, p, r, y, z;
char c;
string name;

signed main(){
    memset(ans, '*', MAXN);
    memset(t, '*', MAXN);
    cin >> name >> n;

    for( int i = 1 ; i <= n * 2 ; i++ ){
        cin >> a;
        if( i % 2 == 1 ){
            for( int j = 0 ; j < a ; j++ ){
                cin >> c;
                if( c == 'A' ) ans[ y * 5 + 1 ] = c;
                if( c == 'B' ) ans[ y * 5 + 2 ] = c;
                if( c == 'C' ) ans[ y * 5 + 3 ] = c;
                if( c == 'D' ) ans[ y * 5 + 4 ] = c;
                if( c == 'E' ) ans[ y * 5 + 5 ] = c;
            }
            y += 1;
        }else{
            for( int j = 0 ; j < a ; j++ ){
                cin >> c;
                if( c == 'A' ) t[ z * 5 + 1 ] = c;
                if( c == 'B' ) t[ z * 5 + 2 ] = c;
                if( c == 'C' ) t[ z * 5 + 3 ] = c;
                if( c == 'D' ) t[ z * 5 + 4 ] = c;
                if( c == 'E' ) t[ z * 5 + 5 ] = c;
            }
            z += 1;
        }
    }

    if( name == "the_wisest_student" ){
        p = n * 5;
    }else{
        for( int i = 1 ; i <= ( n * 5 ) ; i++ ){
            if( i % 5 == 1 ) r = 0;
            if( ans[i] != t[i] ) r += 1;
            if( i % 5 == 0 ){
                if( r == 0 ) p += 5;
                if( r == 1 ) p += 3;
                if( r == 2 ) p += 1;
                if( r >= 3 ) p += 0;
            }
        }
    }
    cout << p;
}
