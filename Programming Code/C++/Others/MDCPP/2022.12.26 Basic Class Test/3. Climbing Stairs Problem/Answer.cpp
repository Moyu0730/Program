#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6 + 5;
int arr[MAXN];

int stair(int n){
    if( n == 0 ) return arr[0];
    if( n == 1 ) return arr[1];
    if( arr[n] ) return arr[n];
    return arr[n] = stair(n-1) + stair(n-2);
}

signed main(){
    int n;
    cin >> n;
    arr[0] = arr[1] = 1;
    cout << stair(n);
}