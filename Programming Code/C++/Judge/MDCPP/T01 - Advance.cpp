#include<iostream>
#include<queue>
#define int long long
using namespace std;

queue<int> que;
int n, a, b, c, ans;

signed main(){
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> a;
        if( a == 1 ){
            cin >> b >> c;
            for( int j = 1 ; j <= c ; j++ ){
                que.push(b);
            }
        }else{
            cin >> b;
            ans = 0;
            for( int j = 1 ; j <= b ; j++ ){
                ans += que.front();
                que.pop();
            }
            cout << ans << '\n';
        }
    }
}
