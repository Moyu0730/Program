#include<iostream>
#include<string>
using namespace std;

int n, ind;
string s = " ";
string M = "M",
        D = "D",
        C = "C",
        L = "L",
        X = "X",
        V = "V",
        I = "I";


signed main(){
    cin >> n;
    ind = 0;
    while( n >= 1000 ){
        n -= 1000;
        s.insert(ind, M);
        ind++;
    }
    while( n >= 100 ){
        if( n >= 900 ){
            n -= 900;
            s.insert(ind, C);
            ind++;
            s.insert(ind, M);
            ind++;
        }else if( n >= 500 ){
            n -= 500;
            s.insert(ind, D);
            ind++;
        }else if( n >= 400 ){
            n -= 400;
            s.insert(ind, C);
            ind++;
            s.insert(ind, D);
            ind++;
        }else{
            n -= 100;
            s.insert(ind, C);
            ind++;
        }
    }
    while( n >= 10 ){
        if( n >= 90 ){
            n -= 90;
            s.insert(ind, X);
            ind++;
            s.insert(ind, C);
            ind++;
        }else if( n >= 50 ){
            n -= 50;
            s.insert(ind, L);
            ind++;
        }else if( n >= 40 ){
            n -= 40;
            s.insert(ind, X);
            ind++;
            s.insert(ind, L);
            ind++;
        }else{
            n -= 10;
            s.insert(ind, X);
            ind++;
        }
    }
    while( n >= 1 ){
        if( n >= 9 ){
            n -= 9;
            s.insert(ind, I);
            ind++;
            s.insert(ind, X);
            ind++;
        }else if( n >= 5 ){
            n -= 5;
            s.insert(ind, V);
            ind++;
        }else if( n >= 4 ){
            n -= 4;
            s.insert(ind, I);
            ind++;
            s.insert(ind, V);
            ind++;
        }else{
            n -= 1;
            s.insert(ind, I);
            ind++;
        }
    }
    cout << s;
}
