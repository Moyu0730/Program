#include<iostream>
using namespace std;

int ans = 0;

int rec( int n ){
    if( n == 0 ) return 0;
    else{
        ans += n;
        rec(n-1);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << rec(n);
}