#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nums1;
vector<int> nums2;
int n, a, ans, len, b1, b2;

signed main(){
    ans = 0;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> a;
        nums1.emplace_back(a);
    }
    for( int i = 1 ; i <= n ; i++ ){
        cin >> a;
        nums2.emplace_back(a);
    }
    int ans, b1, b2, c1, c2;
    ans = 0;
    while( nums1.size() >= 2 ){
        b1 = nums1.back();
        nums1.pop_back();
        b2 = nums2.back();
        nums2.pop_back();
        if( nums1.size() > 2 ){
            if( ( b1 <= nums1.back() ) || ( b2 <= nums2.back() ) ){
                cout << "1 ";
                c1 = nums1.back();
                nums1.pop_back();
                c2 = nums2.back();
                nums2.pop_back();
                if( ( c1 <= nums1.back() ) || ( c2 <= nums2.back() ) ){
                    cout << "2 ";
                    if( ( b1 > c2 > nums1.back() ) || ( b2 > c1 > nums2.back() ) ){
                        ans++;
                    }else{
                        ans += 2;
                    }
                }else{
                    cout << "3 ";
                    nums1.emplace_back(c1);
                    nums2.emplace_back(c2);
                    ans++;
                }
            }
        }else if( nums1.size() == 2 ){
            if( ( b1 <= nums1.back() ) || ( b2 <= nums2.back() )  ){
                ans++;
            }
        }
    }
    cout << '\n' << ans;
}
