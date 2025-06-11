#include <bits/stdc++.h>
using namespace std;

int query(int x) {
    printf("%d 0\n", x); fflush(stdout);
    char s[10]; scanf("%s", s);
    return s[0] == 'b';
}

int main() {
    int n; scanf("%d", &n);
    int c = query(0);
    int L = 1, R = 1e9;
    for (int i = 2; i <= n; i++) {
        int mid = (L + R) >> 1;
        int t = query(mid);
        if (c == t) L = mid + 1;
        else R = mid - 1;
    }
    if (L <= R) printf("%d 0 %d 1\n", L, L);
    else if (L + 1 <= 1e9) printf("%d 1 %d 3\n", L, L + 1);
    else printf("%d 1 %d 3\n", R, R - 1);
    fflush(stdout);
    return 0;
}
