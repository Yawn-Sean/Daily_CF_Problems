#include <bits/stdc++.h>
#define MAXLEN ((int) 1e5)
using namespace std;

char s[MAXLEN + 10];

int main() {
    long long n;
    int q; scanf("%lld%d", &n, &q);
    while (q--) {
        long long x; scanf("%lld%s", &x, s + 1);
        for (int i = 1; s[i]; i++) {
            long long lb = x & (-x);
            if (s[i] == 'U') {
                if (x == (n + 1) / 2) continue;
                if (x & (lb << 1)) x -= lb;
                else x += lb;
            } else if (s[i] == 'L') {
                if (lb == 1) continue;
                x -= lb / 2;
            } else {
                if (lb == 1) continue;
                x += lb / 2;
            }
        }
        printf("%lld\n", x);
    }
    return 0;
}
