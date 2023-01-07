#include<iostream>
using namespace std;

string s, res;

int getNumber( string s ){
    int num = 0, ind = 0;
    while( s[ind] >= '0' and s[ind] <= '9' ){
        num = num * 10 + ((int)s[ind] - 48);
        ind++;
    }
    return num;
}

string recursion( string s, int times ){
    int num = 0, ind = 0;
    string tmp = "", res = "";
    bool flag = false;
    
    // Terminal Condition
    for( int i = 0 ; i < s.size() ; i++ ){
        if( s[i] == '[' ) break;
        if( i == s.size()-1 ) flag = true;
    }

    // If S Only Have Letters
    if( flag ){
        for( int i = 0 ; i < times ; i++ ) tmp += s;
        return tmp;
    }
    
    // If S Includes : Numbers, Letters, and []
    while( ind <= s.size() ){
        if( s[ind] >= '0' and s[ind] <= '9' ){
            string str = "";
            int limit = 0;
            num = 0;
            while( s[ind] >= '0' and s[ind] <= '9' ){
                num = num * 10 + ((int)s[ind] - 48);
                ind++;
            }
            ind++; limit++;
            while( limit != 0 ){
                if( s[ind] == '[' ) limit++;
                else if( s[ind] == ']' ) limit--;
                str += s[ind];
                ind++;
            }
            str.erase(str.size()-1);
            tmp += recursion(str, num);
        }else{
            tmp += s[ind];
            ind++;
        }
    }

    // Output Answer
    for( int i = 0 ; i < times ; i++ ) res += tmp;

    return res;
}

int main(){
    cin >> s;
    cout << recursion(s, 1);
}