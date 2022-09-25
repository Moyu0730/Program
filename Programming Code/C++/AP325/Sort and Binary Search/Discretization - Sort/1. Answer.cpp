#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define N 5

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;

struct point{
    int x,y;
};

// compare by only x
bool pcmp( point s, point t ){
    return s.x < t.x;
}

signed main(){
    point p[N];
    int n = 5;
    srand( time(NULL) );
    
    for( int i = 0 ; i < n ; i++ ) p[i].x = rand() % 10, p[i].y = rand() % 10;
    sort( p, p+n, pcmp );
    
    for( int i = 0 ; i < n ; i++ ) cout << "(" << p[i].x << "," << p[i].y << ") ";
    cout << "\n";
    
    cout << "\nFor Array\n";
    for(int i = 0 ; i < 5 ; i++ ){
        point t = { i * 3 , rand() % 10 };
        int ndx = lower_bound( p, p+n, t, pcmp ) - p;
        if ( ndx < n )
            cout << "Find >= (" << t.x << "," << t.y << ") at [" << ndx << "] = (" << p[ndx].x << "," << p[ndx].y << ")\n";
        else
            cout << "No one >= (" << t.x << "," << t.y << ") \n";
    }

    // For Vector
    cout << "\nFor Vector\n";
    vector<point> v ( p, p+n );
    for(int i = 0 ; i < 5 ; i++ ){
        point t = { i * 3 , rand() % 10 };
        auto q = lower_bound( v.begin(), v.end(), t, pcmp );
        if( q != v.end() )
            cout << "Find >= (" << t.x << "," << t.y << ") at [" << q-v.begin() << "] = (" << q->x << "," << q->y << ")\n";
        else
            cout << "No x >= (" << t.x << "," << t.y << ")\n";
    }

    // Using Pair, Default Compare Function
    cout << "\nCompare by x and then y\n";
    vector<pair<int,int>> a;
    for( point e : v ) a.push_back( { e.x, e.y } );
    for( int i = 0 ; i < 5 ; i++ ){
        pair<int,int> t = { i * 3, rand() % 10 };
        auto q = lower_bound( a.begin(), a.end(), t );
        if ( q != a.end() )
            cout <<  "Find >= (" << t.first << "," << t.second << ") at [" << q - a.begin() << "] = (" << q->first << "," << q->second << ")\n";
        else
            cout << "No x >= (" << t.first << "," << t.second << ")\n";
    }

    cout << "\nCompare by only x\n";
    for( int i = 0 ; i < 5 ; i++ ){
        pair<int,int> t = { i * 3, rand() % 10 };
        // Set t.second to minimum to ignore comparison of y-value
        auto q = lower_bound( a.begin(), a.end(), make_pair(t.first,-1) );
        if ( q != a.end() )
            cout << "Find >= (" << t.first << "," << t.second << ") at [" << q - a.begin() << "] = (" << q->first << "," << q->second << ")\n";
        else
            cout << "No x >= (" << t.first << "," << t.second << ")\n";
    }
    return 0;
}