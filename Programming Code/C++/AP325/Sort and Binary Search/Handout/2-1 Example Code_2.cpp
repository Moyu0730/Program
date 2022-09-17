#include <bits/stdc++.h>
using namespace std;
#define N 10

void showp(pair<int,int> a[], int n) {
    for (int i = 0 ; i < n ; i++ )
        printf("(%1d, %1d) ",a[i].first, a[i].second);
    printf("\n");
    return;
}

int main() {
    pair<int,int> p[N];
    int n = 10;
    for ( int i = 0 ; i < n ; i++ ) p[i] = { rand() % 10, rand()  %10 };
    showp(p,n);

    printf("\nSorted by lexicographic order\n");
    sort(p, p+n);
    showp(p, n);

    printf("\nCopy p to q\n");
    vector<pair<int,int>> q(p, p+n); // copy p to q
    for( auto s : q ) printf("(%d, %d) ", s.first, s.second);

    printf("\n\nSorted by greater order\n");
    sort( q.begin(), q.end(), greater<pair<int,int>>() );
    for( auto s : q ) printf("(%d, %d) ", s.first, s.second);
    
    return 0;
}