#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 50;
const int Mod = 1e9 + 7;
bool arr[MAXN][MAXN];
int x, y;
auto dir = vector<vector<int>> {    {1, 0, 0, 0}, 
                                    {0, 1, 0, 0}, 
                                    {0, 0, -1, 0}, 
                                    {0, 0, 0, -1} };

int solution( int l, int u, int r, int d, int res ){
    if( abs( l - r ) == 2 || abs( u - d ) == 2 ) return res;

    int ans = MAXN, ctn[4]; // ctn -> left, up, right, down

    pair<int, int> a = {0, 0}; 
    pair<int, int> b = {0, 0}; // first for 0, second for 1
    for( int i = u ; i < d ; i++ ){ // a for first column, b for last column
        if( arr[i][l] == 0 ) a.first++;
        else a.second++;
        if( arr[i][r-1] == 0 ) b.first++;
        else b.second++;
    }
    ctn[0] = min(a.first, a.second); ctn[2] = min(b.first, b.second);
    
    a = {0, 0}, b = {0, 0}; // first for 0, second for 1
    for( int i = l ; i < r ; i++ ){ // a for first row, b for last row
        if( arr[u][i] == 0 ) a.first++;
        else a.second++;

        if( arr[d-1][i] == 0 ) b.first++;
        else b.second++;
    }
    ctn[1] = min(a.first, a.second); ctn[3] = min(b.first, b.second);

    for( int i = 0 ; i < 4 ; i++ ){
        int inf[] = { l + dir[i][0], u + dir[i][1], r + dir[i][2], d + dir[i][3] };
        ans = min( ans, solution(inf[0], inf[1], inf[2], inf[3], res + ctn[i]));
    }
    return ans;
}

signed main(){
    opt;
    cin >> y >> x;
    for( int i = 0 ; i < y ; i++ ){
        for( int j = 0 ; j < x ; j++ ){
            cin >> arr[i][j];
        } 
    }
    cout << solution(0, 0, x, y, 0) << '\n'; 
}