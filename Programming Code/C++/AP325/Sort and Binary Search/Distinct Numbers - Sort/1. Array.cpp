#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int arr[MAXN], n, tmp[MAXN], ind;
    memset(tmp, 1e9 +50, sizeof(tmp));
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];
    sort(arr, arr+n);
    for( int i = 0 ; i < n ; i++ ){
        if( arr[i] != tmp[ind] ){
            ind++;
            tmp[ind] = arr[i];
        }
    }
    cout << ind << '\n';
    for( int i = 1 ; i <= ind ; i++ ) cout << tmp[i] << " ";
    cout << '\n';
}