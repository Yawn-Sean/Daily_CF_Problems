#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    if (n == 1) { printf("1\n"); return 0; }
    if (n == 3) { printf("5\n"); return 0; }

    int head = 1, tail = n / 2 + 1;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        int t = mid * 2 - 1;
        if (t * t / 2 + 1 >= n) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head * 2 - 1);
    return 0;
}
