#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#define int long long
using namespace std;

const int MAXN = 5e5 + 50;
int n, k;
long long delta;
int arr[MAXN], pre[MAXN], lps[MAXN], rps[MAXN];
                        // lps and rps stands for Left and Right Prefix Sum

int solution( int left, int right, int level ){

    // Terminal Condition
    if( right - left < 2 or level >= k ) return 0;

    // Calaulate lps array
    delta = 0, lps[left] = 0;
    for( int i = left+1 ; i <= right ; i++ ){
        delta += arr[i-1];
        lps[i] = lps[i-1] + delta;
    }
    // Calaulate rps array
    delta = 0, rps[right] = 0;
    for( int i = right-1 ; i >= left ; i-- ){
        delta += arr[i+1];
        rps[i] = rps[i+1] + delta;
    }

    // Find the best cut point and it can not be two
    long long MAX = 1e20, dif = 0;
    int ind = 0;
    for( int i = left+1 ; i < right ; i++ ){
        dif = abs( rps[i] - lps[i] );
        if( dif < MAX ){
            ind = i;
            MAX = dif;
        }
    }
    
    return arr[ind] + solution(left, ind-1, level+1) + solution(ind+1, right, level+1);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];
    cout << solution(1, n, 0);
}