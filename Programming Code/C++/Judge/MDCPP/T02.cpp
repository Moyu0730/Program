#include<iostream>
#define int long long
using namespace std;

const int MAXN = 1e7 + 50;
int arr[MAXN];
int n, ans;

signed main(){
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> arr[i];
    }

    for( int i = 1; i <= n ; i++ ){
        if( arr[i] == 1 ){
            for( int j = i ; j <= i + 7 ; j++ ){
                if( arr[j] == 0 ) arr[j] = 2;
            }
        }
        if( arr[i] == 0 ){
            arr[i] = 1;
            ans += 1;
            for( int j = i ; j <= i + 7 ; j++ ){
                if( arr[j] == 0 ) arr[j] = 2;
            }
        }
    }
    cout << ans << '\n';
}
