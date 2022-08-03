#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> barcodes;
int a, n, d;

signed main(){
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> a;
        barcodes.emplace_back(a);
    }
    sort(barcodes.begin(), barcodes.end());
    d = 0;
    for( int i = 2 ; i <= n-2 ; i++ ){
        if( barcodes[i-1] == barcodes[i-2] ){
            swap( barcodes[i-1], barcodes[barcodes.size()-d-1]);
            d++;
        }
    }
    for( int i = 0 ; i < n ; i++ ){
        cout << barcodes[i] << " ";
    }
}
