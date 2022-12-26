#include<iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    bool flag = true;
    if( n <= 0 ) return false;
    else if( n % 2 == 0 ) flag = isPowerOfTwo(n/2);
    else return n == 1;
    return flag;
}

int main(){
    int n;
    cin >> n;
    cout << isPowerOfTwo(n);
}