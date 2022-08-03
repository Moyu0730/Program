#include<iostream>
#include<vector>
#define int long long
using namespace std;

vector<int> nums;
vector<vector<int>> ans;
vector<int> vc;
int m, a;

void sub( int n, vector<int>& nums, vector<int> vc ){

}

signed main(){
    cin >> m;
    for( int i = 1 ; i <= m ; i++ ){
        cin >> a;
        nums.emplace_back(a);
    }
    cout << "0";
    sub(0, nums, vc);
}
