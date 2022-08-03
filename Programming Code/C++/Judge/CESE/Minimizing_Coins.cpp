#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
vector<int> coins(MAXN);
vector<int> dp(MAXN);
int n;

int solution( int x ){
    set<int> s;

    if( dp[x] != 0 ) return dp[x];


    s.clear();
    
    for( int i = 0 ; i < n ; i++ ){
        if( x - coins[i] < 0 ) break;
        dp[x - coins[i]] = solution(x - coins[i]) + 1;
        s.insert(dp[x - coins[i]]);
    }
    
    return dp[x] = *s.begin();
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> n >> x;
    coins.resize(n);

    fill(dp.begin(), dp.end(), 0);

    for( int i = 0 ; i < n ; i++ ){
        cin >> coins[i];
        dp[coins[i]] = 1;
    }

    sort(coins.begin(), coins.end());

    dp[0] = 1;

    // for( auto i : coins ){
    //     cout << i << " ";
    // }

    cout << solution(x);
}