#include<iostream>
#define int long long
using namespace std;

int arr[1000050][3];
int num[1000050];
int n, m;

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> num[i];
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= 2 ; j++ ){
            cin >> arr[i][j];
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        m += num[i] * ( arr[i][2] - arr[i][1] ) * 1000;
    }
    cout << m;
}
