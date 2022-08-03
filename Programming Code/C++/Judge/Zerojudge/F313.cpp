#include<iostream>
#define int long long
using namespace std;

const int MAXN = 1e4 +50;
int city[MAXN][MAXN];
int p[MAXN][MAXN];
int r, c, k, m;

void add( int i, int j ){
    if( city[i+1][j] != -1 || city[][] ) p[i+1][j] += city[i+1][j] / k;
    if( city[i-1][j] != -1 ) p[i-1][j] += city[i-1][j] / k;
    if( city[i][j+1] != -1 ) p[i][j+1] += city[i][j+1] / k;
    if( city[i][j-1] != -1 ) p[i][j-1] += city[i][j-1] / k;

    if( city[i+1][j] != -1 ) city[i][j]--;
    if( city[i-1][j] != -1 ) city[i][j]--;
    if( city[i][j+1] != -1 ) city[i][j]--;
    if( city[i][j-1] != -1 ) city[i][j]--;

}

signed main(){
    cin >> r >> c >> k >> m;

    // input city
    for( int i = 1 ; i <= r ; i++ ){
        for( int j = 1 ; j <= c ; j++ ){
            cin >> city[i][j];
        }
    }

    while(m--){
        for( int i = 1 ; i <= r ; i++ ){
            for( int j = 1 ; j <= c ; j++ ){
                if( city[i][j] >= k ) add(i, j);
            }
        }
    }

    for( int i = 1 ; i <= r ; i++ ){
        for( int j = 1 ; j <= c ; j++ ){
            cout << p[i][j] << " ";
        }
        cout << '\n';
    }
}
