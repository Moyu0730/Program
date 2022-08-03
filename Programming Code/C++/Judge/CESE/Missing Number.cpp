#include<iostream>
#include<vector>
using namespace std;

vector<bool> v;
int n, x, ind;

int main (){
    cin >> n;
    v.resize(n+1);
    for( int i = 1 ; i <= n - 1 ; i++ ){
        cin >> x;
        v[x] = 1;
    }
    v[0] = 1;
    ind = 0;
    for( auto i : v ){
        ind++;
        if( !i ){
            cout << ind-1;
            break;
        }
    }
}
