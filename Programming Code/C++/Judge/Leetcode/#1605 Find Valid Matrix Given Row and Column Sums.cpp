#include<iostream>
#include<vector>
#define int long long
using namespace std;

vector<vector<int>> ans;
vector<int> rowSum;
vector<int> colSum;
int n, v, m, len, in;

signed main(){
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> v;
        rowSum.emplace_back(v);
    }
    for( int i = 1 ; i <= n ; i++ ){
        cin >> v;
        colSum.emplace_back(v);
    }
    len = colSum.size();

    for( int i = 0 ; i < len ; i++ ){
        ans[i][0] = rowSum[i];
    }

    for( int j = 0 ; j < len ; j++ ){
        m = 0;
        for( int i = 0 ; i < len ; i++ ){
            if( m + ans[i][j] > colSum[j] ){
                in = colSum[j] - m;
                m += in;
                ans[i][j+1] = ans[i][j] - in;
                ans[i][j] = in;
            }else if( m < colSum[j] ){
                m += ans[i][j];
            }else{
                ans[i][j+1] = ans[i][j];
                ans[i][j] = 0;
            }
        }
    }
    cout << '\n';
    for( int i = 0 ; i < len ; i++ ){
        for( int j = 0 ; j < len ; j++ ){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}
