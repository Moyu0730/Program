//#include<iostream>
//#include<iomanip>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 1e8 + 50;
//const int Mod = 1e9 + 7;
//string s;
//int ans = 0;
//
//int solution( int side, int ind ){
//    cout << "Side: "<< side << " " << ind << '\n';
//    int arr[6]; // LeftUp, RightUp, LeftDown, RightDown -> index start from 1
//    int i = 0, j = 0;
//    while( i != 4 ){
//        cout << "i: " << i << " " << j << " " << ind+j << '\n';
//        cout << "Word: " << s[ind+j] << "\n";
//        if( s[ind+j] == '2' ){
//            ind = solution( side/2, ind+j+1 ) - 1;
//            j = 0;
//        }else{
//            if( s[ind+j] == '1' ) ans += (side/2) * (side/2);
//            i++;
//        }
//        j++;
//
//    }
//    cout << "End " << side << " " << ans << " " << ind+j << '\n';
//    return ind+j;
//}
//
//signed main(){
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    int n;
//    cin >> s >> n;
//    cout << '\n';
//    cout << '\n';
//    for( int i = 0 ; i < s.size() ; i++ ){
//        cout << i << " " << s[i] << '\n';
//    }
//    cout << '\n';
//    cout << '\n';
//    solution(n, 1);
//    cout << ans;
//}

#include <iostream>
using namespace std;

int len, idx;
string s;

int func(int w){
    idx++;
    if (s[idx] == '0') return 0;
    else if (s[idx] == '1') return w * w;
    else {
        int ans = 0;
        for (int i = 0; i < 4; i++){
            ans += func(w/2);
        }
        return ans;
    }
}

int main() {
    cin >> s >> len;
    idx = -1;
    cout << func(len) << "\n";
}
