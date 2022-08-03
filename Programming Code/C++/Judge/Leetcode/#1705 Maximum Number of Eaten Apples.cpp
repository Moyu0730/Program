#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

vector<int> apples;
vector<int> days;       // ➦ This is used to store apples
priority_queue< pair<int,int>, vector< pair<int,int> >, greater<>> pq;
                     // ➥ This is used to store days

int ans, len, x, n;

signed main(){
    cin >> n;

    // Input
    for( int i = 1 ; i <= n ; i++ ){
        cin >> x;
        apples.emplace_back(x);
    }
    for( int i = 1 ; i <= n ; i++ ){
        cin >> x;
        days.emplace_back(x);
    }

    len = apples.size();
           // ➦ i represents the number of days that the loop is currently executed
    for( int i = 1 ; ( i <= len ) || ( !pq.empty() ) ; i++ ){
        if( i <= len ){
                                          // ➦ i-1 is because <vector> apples store data from index "0"
            pq.push( { i + days[i-1], apples[i-1] } );
        }               // ➥ This means days are going on ➨ Add one to a day


                   //    ➦ The purpose of this is to terminate the loop when priority_queue is empty
                   // !pq.empty()                                  ➦ This is used to determin if there are apples to eat
        while( ( !pq.empty() ) && ( pq.top().first <= i || pq.top().second <= 0 ) ){
            pq.pop();                   // ➥ This is used to determin whether an apple is rotten
        }

        // if apples exist then increment count
        if( !pq.empty() ){
            ans++;
            auto val = pq.top();
            pq.pop();
            val.second--;
            if( val.second > 0 ) pq.push(val);  // This is used to clean the apple that will rotten today
        }
    }
}
