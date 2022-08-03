#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

const int Mod = 1e9 + 7;

vector<string> v;
stack<string> st;
int n, k;
string s;

int dfs( int len ){

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> k;
    v.resize(k+5);
//      int   size_t
    for( int i = 1 ; i <= k ; i++ ){
        cin >> v[i];
    }
    dfs(0);
}

/*

You are given a string of length n and a dictionary containing k words. In how many ways can you create the string using the words?

# Input

The first input line has a string containing n characters between a–z.

The second line has an integer k: the number of words in the dictionary.

Finally there are k lines describing the words. Each word is unique and consists of characters a–z.

# Output

Print the number of ways modulo 1e9+7.

# Constraints

1 ≤ n ≤ 5000
1 ≤ k ≤ 1e5

the total length of the words is at most 106

# Example

## Input:

ababc
4
ab
abab
c
cb

## Output:
2

## Explanation: The possible ways are ab+ab+c and abab+c.
*/