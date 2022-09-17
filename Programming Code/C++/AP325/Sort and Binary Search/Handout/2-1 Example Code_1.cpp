#include <bits/stdc++.h>
using namespace std;
#define N 10

void show(int a[], int n) {
    for ( int i = 0 ; i < n ; i++ ) printf("%2d ", a[i]);
    printf("\n");
    return;
}

bool cmp1(int s, int t) {
    return s > t;
}

struct point {
    int x, y;
};

bool cmp2(point &s, point &t) {
    return s.x < t.x;
}

bool cmp3(point &s, point &t) {
    return s.y > t.y;
}
bool cmp4(point &s, point &t) {
    return s.x + s.y < t.x + t.y;
}

void showp(point a[], int n) {
    for (int i = 0 ; i < n-1 ; i++ )
        printf("(%2d, %2d) ",a[i].x, a[i].y);
        printf("(%2d, %2d)\n",a[n-1].x, a[n-1].y);
    return;
}

int main() {
    int a[N], n = 10;
    
    for (int i = 0 ; i < n ; i++ ) a[i] = rand() % 99;
    show(a,n);
    // printf("\nFrom large to small\n");
    // sort(a, a+n, cmp1);
    // show(a, n);

    printf("\nUsing greater\n");
    sort(a, a+n, greater<int>());
    show(a, n);
    
    point p[N];
    for (int i = 0 ; i < n ; i++ ) p[i].x = rand() % 99, p[i].y = rand() % 99;
    printf("\n%d Points on the plane\n");
    showp(p, n);

    printf("\nSorted for x from small to large\n");
    sort(p, p+n, cmp2);
    showp(p, n);

    printf("\nSorted for y from large to small\n");
    sort(p, p+n, cmp3);
    showp(p, n);
    
    printf("\nSorted for x + y from small to large\n");
    sort(p, p+n, cmp4);
    showp(p, n);
    
    return 0;
}