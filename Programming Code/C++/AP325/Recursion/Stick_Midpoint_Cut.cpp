#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 5e4;
const int Mod = 1e9 + 7;
long long cut[MAXN];

long long solution( int left, int right){
      if( right - left <= 1 ) return 0;

      long long len = cut[right] - cut[left];
      long long mid = ( cut[right] + cut[left] ) / 2;
      int ctn = lower_bound( cut + left, cut + right, mid) - cut; // Binary Search

      if( cut[ctn-1] - cut[left] >= cut[right] - cut[ctn] ) ctn--; // To make sure if ctn - 1 is better

      return len + solution(left, ctn) + solution(ctn, right); // Recursive
}

signed main(){
      // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
      int n, l;
      cin >> n >> l;
      cut[0] = 0; cut[n+1] = l;
      for( int i = 1 ; i <= n ; i++ ) cin >> cut[i];
      cout << solution(0, n+1);
}

/*
4 10
1 2 4 6 

      - - - - - - - - - - -
index 0 1 2 3 4 5 6 7 8 9 10
cut     | |   |   |

ctn_ans 10 ( 10 - 0 )
      - - - - | - - - - - -
index 0 1 2 3 4 5 6 7 8 9 10

ctn_ans 10 + 4 ( 4 - 0 ) = 14
      - - | - | - - - - - - -
index 0 1 2 3 4 5 6 7 8 9 10

ctn_ans 14 + 2 ( 2 - 0 ) = 16
      - | | - | - - - - - - -
index 0 1 2 3 4 5 6 7 8 9 10

ctn_ans 16 + 6 ( 10 - 4 ) = 22
      - | | - | - | - - - - 
index 0 1 2 3 4 5 6 7 8 9 10

*/