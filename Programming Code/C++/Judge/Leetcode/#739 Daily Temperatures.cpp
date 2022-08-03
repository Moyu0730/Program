#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> vc;
vector<int> ans;
stack<int> s;
int n, x;

signed main(){
    cin >> n;
    vc.resize(n);
    ans.resize(n);
    for( int i = 1 ; i <= n ; i++ ){
        cin >> x;
        vc[i] = x;
    }
    for( int i = 0 ; i < n ; i++ ){
        if( s.empty() ){
            s.push(i);
        }else if( vc[i] < vc[s.top()] ){
            s.push(i);
        }else{
            while( !s.empty() && vc[i] < vc[s.top()] ){
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
    }
    for( int i = 0 ; i < vc.size() ; i++ ){
        cout << ans[i] << " ";
    }
}
