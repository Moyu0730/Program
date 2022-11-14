#include <bits/stdc++.h>
using namespace std;
#define N 10
#define P 10

void Demo_Multiset(){
    multiset<int> S;
    cout << "Insert : ";
    for ( int i = 0 ; i < N ; i++ ) {
        int t = rand() % P;
        S.insert(t);
        cout << t << " ";
    }

    cout << "\n\nTraversal after insertion : ";
    for (int e : S) {
        cout << e << " ";
    }

    cout << "\n\nClear and re-insert data : ";
    S.clear(); // clear set
    vector<int> v( { 5, 5, 2, 3, 7, 7, 8 } );
    S.insert( v.begin(), v.end() );
    for (int e : S) cout << e << " ";

    cout << "\n\nAfter S.erase(5) : ";
    S.erase(5);
    for (int e : S)
    cout << e << " ";

    cout << "\n\nAfter erase one of 7 : ";
    auto it = S.find(7);
    if ( it != S.end() ) S.erase(it);
    for (int e: S) cout << e << " ";
    cout << "\n";
}

void Demo_Map(){
    map<char, int> M;
    char str[100] = "a demo of c++ map", ch;
    int len = strlen(str); // Get the length of str array "str"
    for ( int i = 0 ; i < len ; i++ ) M[str[i]] += 1; // Produce a Map which store ( *Char*, *The number of occurrences of the char* )

    cout << "After insert " << str << " : ";
    for ( auto e : M ) cout << "( " << e.first << " : " << e.second << " ) ";
    cout << "\n\n";
    ch = 'x';
    auto mit = M.find(ch);
    if ( mit == M.end() ) cout << "No \"" << ch << "\" in M\n\n";
    else cout << "count ( " << ch << ") = " << mit->second << "\n\n";
    ch = 'm';
    cout << "M[" << ch << "] = " << M[ch] << "\n\n";
    ch = 'y';
    cout << "M[" << ch << "] = " << M[ch] << "\n\n";
    M['y'] = 5;
    cout << "After M['y'] = 5, M[" << ch << "] = " << M[ch] << "\n\n";
    
    cout << "After erase('y'), ";
    M.erase(ch);
    mit = M.find(ch);
    if ( mit == M.end() ) cout << "No \"" << ch << "\" in M\n\n";
    M[ch];
    cout << "After M['y'], M[" << ch << "] = " << M[ch] << "\n\n";
}

int main() {
    cout << "** Demo Multiset ***\n\n";
    Demo_Multiset();
    cout << "\n*** Demo Map ***\n\n";
    Demo_Map();

    return 0;
}
