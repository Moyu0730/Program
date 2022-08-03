#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define int long long
using namespace std;

/*
 Line => i
 |
 ˇ
 | | | => Row => j
 | | |
*/

const int MAXN = 10;
int Seat[MAXN][MAXN];
int N_seat[MAXN][MAXN];
int p[MAXN][MAXN];
int Possible_condition, Possible_line, Possible_row;
int Repeat, Middle_One_amount, Side_One_amount, swi, Remember_One_A;
bool c, option;

void Random_Line_and_Row_Side(){
    // Line
    if( option == 1 ){
        srand( (unsigned) time(0) );
        Possible_line = ( rand() % 7 ) + 4;
        while( Possible_line > 7 || Possible_line < 4 ){
          srand( (unsigned) time(0) );
          Possible_line = ( rand() % 7 ) + 4;
    }
    }else{
        srand( (unsigned) time(0) );
        Possible_line = ( rand() % 3 ) + 1;
        while( Possible_line > 3 || Possible_line < 1 ){
          srand( (unsigned) time(0) );
          Possible_line = ( rand() % 3 ) + 1;
        }
    }

    // Row
    srand( (unsigned) time(0) );
    Possible_row = ( rand() % 5 ) + 2;
    while( Possible_row > 5 || Possible_row < 2 ){
        srand( (unsigned) time(0) );
        Possible_row = ( rand() % 5 ) + 2;
    }
}

void Random_Line_and_Row_Middle(){

    // Line
    if( option == 1 ){
        srand( (unsigned) time(0) );
        Possible_line = ( rand() % 7 ) + 4;
        while( Possible_line > 7 || Possible_line < 4 ){
          srand( (unsigned) time(0) );
          Possible_line = ( rand() % 7 ) + 4;
        }
    }else{
        srand( (unsigned) time(0) );
        Possible_line = ( rand() % 3 ) + 1;
        while( Possible_line > 3 || Possible_line < 1 ){
          srand( (unsigned) time(0) );
          Possible_line = ( rand() % 3 ) + 1;
        }
    }

    // Row
    srand( (unsigned) time(0) );
    swi = rand() % 3;
    switch( swi ){
        case 2:
            Possible_row = 1;
            break;
        default:
            srand( (unsigned) time(0) );
            Possible_row = ( rand() % 7 ) + 6;
            while( Possible_row > 7 || Possible_row < 6 ){
                srand( (unsigned) time(0) );
                Possible_row = ( rand() % 7 ) + 6;
            }
            break;
    }

}

void Condition_One(){

    // Side - OK - Down
    cout << "Part One Start" << '\n';
    option = 1;

    for( int i = 4 ; i <= 7 ; i++ ){
        for( int j = 1 ; j <= 7 ; j++ ){

            if( j == 2 || j == 3 || j == 4 || j == 5 ){
                continue;
            }

            Repeat = 0;
            Possible_line = 0;

            while( Possible_line != i && Repeat == 0 ){

                Random_Line_and_Row_Side();

                while( Possible_line == i ){
                    Random_Line_and_Row_Side();
                }

                if( N_seat[Possible_line][Possible_row] == 0 ){
                    N_seat[Possible_line][Possible_row] = Seat[i][j];
                    break;
                }

            }
        }
    }

    cout << "Part One Finish" << '\n' << '\n';

    // cout part one
    for( int i = 1 ; i <= 7 ; i++ ){
        for( int j = 1 ; j <= 7 ; j++ ){
            cout << N_seat[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    // Middle
    Middle_One_amount = 0;
    for( int i = 4 ; i <= 7 ; i++ ){
        for( int j = 2 ; j <= 5 ; j++ ){

            Repeat = 0;
            Possible_line = 0;
            while( Possible_line != i && Repeat == 0 && Middle_One_amount <= 8){

                if( Middle_One_amount < 8 ){

                    Random_Line_and_Row_Middle();

                    while( Possible_line == i ){
                        Random_Line_and_Row_Middle();
                    }

                    if( N_seat[Possible_line][Possible_row] == 0 ){
                        N_seat[Possible_line][Possible_row] = Seat[i][j];
                        Middle_One_amount++;
                        break;
                    }
                }

                if( Middle_One_amount == 8 ){
                    break;
                }
            }

                c = 0;
                if( Middle_One_amount >= 8 && Middle_One_amount <= 12 ){
                    for( int a = 4 ; a <= 7 ; a++ ){
                        for( int b = 1 ; b <= 7 ; b++ ){

                            if( b == 2 || b == 3 || b == 4 || b == 5 ){
                                continue;
                            }

                            if( N_seat[a][b] == 0 ){
                                N_seat[a][b] = Seat[i][j];
                                Middle_One_amount++;
                                c = 1;
                                break;
                            }

                        }
                    if(c == 1) break;
                    }
                }

                c = 0;
                if( Middle_One_amount == 12 ){
                    Remember_One_A = 4;
                }
                if( Middle_One_amount >= 12 && Middle_One_amount < 16 ){
                    for( int a = Remember_One_A ; a <= 7 ; a++ ){
                        for( int b = 1; b <= 7 ; b++ ){
                            if( N_seat[a][b] == 0 ){
                                Remember_One_A = a;
                                N_seat[a][b] = Seat[i][j];
                                Middle_One_amount++;
                                c = 1;
                                break;
                            }
                        }
                    if(c == 1) break;
                    }
                }
        }
    }

    cout << '\n';
    cout << "Part Two Finish\n";
    for( int i = 1 ; i <= 7 ; i++ ){
        for( int j = 1 ; j <= 7 ; j++ ){
            cout << N_seat[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    option = 0;

    for( int i = 1 ; i <= 3 ; i++ ){
        for( int j = 1 ; j <= 7 ; j++ ){

            if( j == 2 || j == 3 || j == 4 || j == 5 ) continue;

            Repeat = 0;
            Possible_line = 0;

            while( Possible_line != i && Repeat == 0 ){

                Random_Line_and_Row_Side();

                while( Possible_line == i ){
                    Random_Line_and_Row_Side();
                }

                if( N_seat[Possible_line][Possible_row] == 0 ){
                    N_seat[Possible_line][Possible_row] = Seat[i][j];
                    break;
                }

            }
        }
    }

    cout << '\n';
    cout << "Part Three Finish" << '\n';
    for( int i = 1 ; i <= 7 ; i++ ){
        for( int j = 1 ; j <= 7 ; j++ ){
            cout << N_seat[i][j] << " ";
        }
        cout << '\n';
    }

    cout << '\n' << '\n';

    // Middle
    Middle_One_amount = 0;
    for( int i = 1 ; i <= 3 ; i++ ){
        for( int j = 2 ; j <= 5 ; j++ ){

            Repeat = 0;
            Possible_line = 0;

            while( Possible_line != i && Repeat == 0 && Middle_One_amount <= 5 ){

                if( Middle_One_amount < 5 ){

                    Random_Line_and_Row_Middle();

                    while( Possible_line == i ){
                        Random_Line_and_Row_Middle();
                    }

                    if( N_seat[Possible_line][Possible_row] == 0 ){
                        N_seat[Possible_line][Possible_row] = Seat[i][j];
                        Middle_One_amount++;
                        break;
                    }
                }

                if( Middle_One_amount == 5 ){
                    break;
                }
            }

            c = 0;
            if( Middle_One_amount >= 5 && Middle_One_amount <= 10 ){
                for( int a = 1 ; a <= 3 ; a++ ){
                    for( int b = 1 ; b <= 7 ; b++ ){

                        if( b == 2 || b == 3 || b == 4 || b == 5 ) continue;

                        if( N_seat[a][b] == 0 ){
                            N_seat[a][b] = Seat[i][j];
                            Middle_One_amount++;
                            c = 1;
                            break;
                        }

                    }
                    if(c == 1) break;
                }
            }

            c = 0;
            Remember_One_A = 1;

            if( Middle_One_amount >= 9 ){
                for( int a = Remember_One_A ; a <= 3 ; a++ ){
                    for( int b = 1; b <= 7 ; b++ ){
                        if( N_seat[a][b] == 0 ){
                            Remember_One_A = a;
                            N_seat[a][b] = Seat[i][j];
                            Middle_One_amount++;
                            c = 1;
                            break;
                        }
                    }
                    if(c == 1) break;
                }
            }
        }
    }

    cout << '\n';
    cout << "Part Four Finish" << '\n';
    for( int i = 1 ; i <= 7 ; i++ ){
        for( int j = 1 ; j <= 7 ; j++ ){
            cout << N_seat[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    // Change
    for( int i = 1 ; i <= 7 ; i++ ){
        if( i <= 4 ){
            for( int j = 1 ; j <= 7 ; j++ ){
                p[i][j] = N_seat[i][j];
            }
        }else{
            for( int j = 1 ; j <= 7 ; j++ ){
                N_seat[i-4][j] = N_seat[i][j];
            }
        }
    }
    for( int i = 1 ; i <= 4 ; i++ ){
        for( int j = 1 ; j <= 7 ; j++  ){
            N_seat[i+3][j] = p[i][j];
        }

    }

    cout << '\n';
    cout << "Final" << '\n';
    for( int i = 1 ; i <= 7 ; i++ ){
        for( int j = 1 ; j <= 7 ; j++ ){
            cout << N_seat[i][j] << " ";
        }
        cout << '\n';
    }
}

void Condition_Two(){
    cout << "2";
}

void Condition_Three(){
    cout << "3";
}

signed main() {
    srand (time(NULL));
//    Possible_condition = rand() % 3 + 1;
    Possible_condition = 1;
    cout << "請打出現在的座位：";
    for( int i = 1 ; i <= 7 ; i++ ){
        for( int j = 1 ; j <= 7 ; j++ ){
            cin >> Seat[i][j];
        }
    }
    cout << '\n' << "GO" << '\n' << '\n';

    switch( Possible_condition ){
        case 1:
            Condition_One();
            break;
        case 2:
            Condition_Two();
            break;
        default:
            Condition_Three();
            break;
    }
}
