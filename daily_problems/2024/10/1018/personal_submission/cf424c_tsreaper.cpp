#include <bits/stdc++.h>
using namespace std;

int calc(int x) {
    if (x % 4 == 0) return x;
    else if (x % 4 == 1) return 1;
    else if (x % 4 == 2) return x + 1;
    else return 0;
}

int main() {
    int n; scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int d = (n + 1) / i, r = (n + 1) % i;
        if (d & 1) ans ^= calc(i - 1);
        if (r > 0) ans ^= calc(r - 1);
    }
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        ans ^= x;
    }
    printf("%d\n", ans);
    return 0;
}
