#include<iostream>
using namespace std;

int integer[] = {  1000,  900, 500, 400 , 100,   90,  50,   40,  10,    9,   5,    4,   1};
string roman[] = {  "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
int main(){
    int n; 
    string ans;
    cin >> n;
    for(int i = 0 ; i < 13 ; i++ ){
        while( n >= integer[i] ) {
            ans += roman[i];
            n -= integer[i];
        }
    }
    cout << ans;
}