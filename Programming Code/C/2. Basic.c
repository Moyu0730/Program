#include<stdio.h>

int main(){
    int n;
    printf("Enter N : ");
    scanf("%d", &n);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= i ; j++ ){
            if( i == n ){
                printf("*");
                continue;
            }

            if( j == 1 || j == i ){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}