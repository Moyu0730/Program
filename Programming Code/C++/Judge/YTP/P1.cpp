#include <iostream>
#include <vector>
#define eb emplace_back
#define pb pop_back
using namespace std;

const int MAXN = 1e5 + 50;
vector<int> v;
vector< pair<int, int> > task;
vector<int> op;
int n, m, x;

int find_ind_v( int ind ){
    int len = v.size();
    for( int i = 0 ; i <= len ; i++ ){
        if( v[i] == ind ) return i;
    }
}

bool find_op( int num ){
    for( auto ind : op ){
        if( ind == num ) return 1;
    }
    return 0;
}

bool find_v( int num ){
    for( auto ind : v ){
        if( ind == num ) return 1;
    }
    return 0;
}

bool sol( int l ){
    if( v.size() == n ) return 1;

    for( int i = 1 ; i <= n ; i++ ){
        if( find_op(i) ){
            continue;
        }else{
            op.eb(i);
        }

        int a = task[i].first;
        int b = task[i].second;

        if( find_v(a) ) v.erase(v.begin() + find_ind_v(a));
        else v.eb(a);

        if( find_v(b) ) v.erase(v.begin() + find_ind_v(b));
        else v.eb(b);

        sol(l+1);
    }
    return 0;
}

// 0 -> Dark, 1 -> Light
signed main() {
    cin >> n >> m;
    while( !v.empty() ){
        v.pb();
    }
    task.resize(m+1);
    for( int i = 1 ; i <= n ; i++ ){
        cin >> x;
        if( x == 0 ) v.eb(i);
    }
    for( int i = 1 ; i <= m ; i++ ){
        cin >> task[i].first >> task[i].second;
    }
    if( sol(0) ){
        cout << "Yes";
        int len = op.size();
        cout << len;
        for( int i = 0 ; i < len ; i++ ){
            cout << op[i] << " ";
        }
    }else{
        cout << "No";
    }
}
