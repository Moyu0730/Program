#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#define int long long
using namespace std;

const int MAXN = 5e5 + 50;
const int M = 1e9;
int n, k;
int arr[MAXN];
int pre[MAXN];

int solution( int left, int right, int level ){
    if( right - left <= 2 || level == k ) return 0;

    int leftSum, rightSum;
    pair<int, int> p (M, M); // pair -> ctn, dif
    for( int i = left+1 ; i < right ; i++ ){
        leftSum = 0, rightSum = 0;
        // cout << i << "\n";
        // cout << "Left ";
        for( int j = left ; j < i ; j++ ){
            leftSum += pre[i-1] - pre[j-1]; 
            // cout << leftSum << " ";
        } 
        // cout << '\n' << "Right ";
        for( int j = i+1 ; j <= right ; j++ ){
            rightSum += pre[j] - pre[i]; 
            // cout << rightSum << " ";
        } 
        //cout << '\n';
        //cout << "Ans " << i << " " << leftSum << " " << rightSum << " " << abs( leftSum - rightSum ) << " " << p.second << "\n";
        if( abs( leftSum - rightSum ) < p.second ){
            p.first = i;
            p.second = abs( leftSum - rightSum );
        }
        //cout << "PAIR " << p.first << " " << p.second << '\n';
    }
    //cout << "P: " << p.first << "\n";
    return arr[p.first] + solution(left, p.first-1, level+1) + solution(p.first+1, right, level+1);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    arr[0] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> arr[i];
        pre[i] = pre[i-1] + arr[i];
    }
    // for( int i = 1 ; i <= n ; i++ ) cout << pre[i] << " ";
    // cout << '\n';
    cout << solution(1, n, 0);
}