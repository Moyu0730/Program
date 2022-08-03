#include<stdio.h>

// void swap( int* val1, int* val2 ){ // 將傳入的 a_p 丟到 val1 中、b_p 丟到 val2 中 
//     int temp = *val1; // 將 val1 的值丟到 temp 中
//     *val1 = *val2;  // val2 的值丟到 val1 中
//     *val2 = temp; // 將 temp 丟到 val2 中
// }

typedef struct{
    int number;
    int score[3];
    char id;
}STU_INFO;

int main(){
    // int a, b; // 宣告 2 個 int 變數 a 跟 b
    
    // scanf("%d %d", &a, &b); // 輸入 a 跟 b

    // // int* a_p; // 宣告一個用來存指標的變數 a_p
    // // int* b_p; // 宣告一個用來存指標得變數 b_p
    // // a_p = &a; // 把 int 變數 a 的地址丟到 a_p 中
    // // b_p = &b; // 把 int 變數 b 的地址丟到 b_p 中

    // swap(&a, &b); // 呼叫 swap 副函式，並把 a_p 跟 b_p 丟到 swap 中

    // printf("%d %d\n", a, b); // 輸出 a_p 跟 b_p 裡面存的值

    STU_INFO stu;
    stu.number = 10;
    printf("%d", stu.number);
}

/*
程式中的變數型態：

a 跟 b -> int 型態的值
a_p 跟 b_p -> int 型態的變數地址
*a_p 跟 *b_p -> int 型態的值
val1 跟 val2 -> int 型態的變數地址
*val1 跟 *val2 -> int 型態的值
temp -> int 型態的值

*/