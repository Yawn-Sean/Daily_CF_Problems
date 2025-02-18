#include <bits/stdc++.h>

using namespace std;
using li = long long;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int d, m;
        scanf("%d%d", &d, &m);
        li ans = 1LL;
        int n = 31 - __builtin_clz(d);
        int last = 0;
        for (int i = 0; i <= n; i++) {
            int curr = (1 << (i + 1)) - 1;
            ans = ans * (min(d, curr) - last + 1) % m;
            last = curr;
        }
        printf("%d\n", (ans + m - 1) % m);
    }
    return 0;
}

