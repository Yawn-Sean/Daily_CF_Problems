#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, m;
        scanf("%d %d %d", &a, &b, &m);
        int k = 1 << (31 - __builtin_clz(m));
        auto f = [k] (int x) -> int {
            return x / k + (x % k == k - 1);
        };
        printf("%d\n", f(b) - f(a - 1));
    }
    return 0;
}

