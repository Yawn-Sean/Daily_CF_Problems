#include <bits/stdc++.h>
using namespace std;

int n;

int query(int len) {
    printf("? ");
    for (int i = 1; i <= len; i++) printf("0");
    for (int i = len + 1; i <= n; i++) printf("1");
    printf("\n"); fflush(stdout);
    int x; scanf("%d", &x);
    return x;
}

int main() {
    scanf("%d", &n);
    int b = query(n);
    int head = 1, tail = n;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        int a = query(mid);
        int x = (a + b + mid - n) / 2;
        if (x == 0 || x == mid) head = mid + 1;
        else tail = mid;
    }

    int a = query(1);
    int x = (a + b + 1 - n) / 2;
    if (x == 0) printf("! %d %d\n", head - 1, head);
    else printf("! %d %d\n", head, head - 1);
    fflush(stdout);
    return 0;
}
