#include <bits/stdc++.h>
using namespace std;
#define N 10
#define P 10

int main() {
    set<int> S; // a set S for storing int
    
    cout << "Insert: ";
    for ( int i = 0 ; i < N ; i++ ){
        int t = rand() % P;
        S.insert(t); // insert an element into S
        cout << t << " ";
    }
    
    cout << "\n\nTraversal after insertion : ";
    for ( auto it = S.begin() ; it != S.end() ; it++ ) cout << *it << " "; // iterator as a pointer
    
    cout << "\n\nAnother traversal for (int e : S) : ";
    for (int e : S) { // for each element e in S, do ...
        cout << e << " ";
    }

    cout << "\n\nClear and re-insert data : ";
    S.clear(); // clear set t empty
    for ( int i = 0 ; i < N ; i++ ) S.insert( i * 5 );
    for (int e : S) cout << e << " ";
    cout << "\n\n";

    // To find if an element in the set
    auto it = S.find(15);
    if (it != S.end() ) // return end() when not found
        cout << "find 15 in S\n\n";
    else cout << "15 is not in S\n\n";

    int x = 15;
    cout << "After S.erase(15)\n\n";
    S.erase(x); // erase element of value x
    it = S.find(x);
    if (it != S.end() ) cout << "find" << x << " in S\n\n";
    else cout << x << " is not in S\n\n";

    // find lower_bound, the first one >= x
    it = S.lower_bound(x);
    if ( it != S.end() ) cout << "lower_bound of " << x << " is " <<  *it << "\n\n";
    else cout << "no lower_bound of " << x << "\n";
    
    // find upper_bound, the first one > x
    x = ( N - 1 ) * 5;
    it = S.upper_bound(x);
    if (it != S.end() ) cout << "upper_bound of " << x << " is " <<  *it << "\n\n";
    else cout << "no upper_bound of " << x << "\n";
    return 0;
}