#include<stdio.h>
#include<stdlib.h>
#include<time.h>

signed main(){

    int i;

    srand((unsigned) time (NULL));

    for( int i = 0 ; i < 5 ; i++ ){
        printf("%d\n", rand());
    }

}