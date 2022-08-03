#include<stdio.h>

const int MAXN = 1000;
int dp[MAXN];

int stair(int n){
    if( n == 0 )	// 當遞迴直到第 0 層時就進入 if
        return dp[0];	// 回傳第 0 層的值（1）
    if( n == 1 )	// 當遞迴直到第 1 層時就進入 if
        return dp[1];	// 回傳第 1 層的值（1）
    if( dp[n] )    // 當 dp[n] 已經跑過的時候就用直接把之前儲存過的值拿來用
        return dp[n];	// 回傳第 n 層的值
    return dp[n] = stair(n-1) + stair(n-2);	   // 因為已知要到第 n 層只能從 n - 1 層跟 n - 2 層往上走
}

signed main(){
    int n;
    scanf("%d", &n);
    dp[0] = dp[1] = 1;	
	// 先設定第 0 層跟第 1 層皆為 1
		// 到第 1 層的方法只有一種
		// 到第 2 層的方法只有 2 => dp[1]（1） + dp[0]（1） 種
    printf("%d", stair(n));
}