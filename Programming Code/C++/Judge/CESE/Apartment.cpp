#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

// const int MAXN;
const int Mod = 1e9 + 7;

signed main(){
    long long n, m, k, ans = 0, ind = 0;
    cin >> n >> m >> k;
    vector<long long> people(n);
    vector<long long> apartment(m);
    for( int i = 0 ; i < n ; i++ ) cin >> people[i];
    for( int i = 0 ; i < m ; i++ ) cin >> apartment[i];
    sort(people.begin(), people.end());
    sort(apartment.begin(), apartment.end());
    for( int i = 0 ; i < n ; i++ ){
        while( ind < m ){
            if( apartment[ind] + k < people[i] ){
                ind++;
            }else if( apartment[ind] - k > people[i] ){
                break;
            }else{
                ind++, ans++;
                break;
            }
        }
    }
    cout << ans;
}