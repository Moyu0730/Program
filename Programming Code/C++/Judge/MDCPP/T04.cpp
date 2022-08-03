#include<iostream>
#define int long long
using namespace std;

int arr[6];
int sor[6];
int n;

signed main(){
    for( int i = 1 ; i <= 5 ; i ++ ){
        cin >> arr[i];
    }

    for( int i = 4 ; i > 0 ; i-- ){
        for( int j = 1 ; j <= i ; j++ ){
            if( arr[j] > arr[j+1] ){
                n = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = n;
            }
        }
    }
    cout << arr[3];
}
