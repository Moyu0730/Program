#include <iostream>
#define int long long
using namespace std;

signed main(){
    int n, i, j;
    cin >> n;
    for( i = 1 ; i <= n ; i++ ){
      for( j = 1 ; j <= n+2 ; j++ ){
        if( j < i || j >= n - i){
            cout << " ";
        }else{
            cout << "*";
        }
      }
      cout << '\n';
      cout << "cool\n" << endl;
    }
}
