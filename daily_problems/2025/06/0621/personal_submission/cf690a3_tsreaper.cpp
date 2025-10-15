#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, K; scanf("%d%d", &n, &K); K--;
    int sm = 0;
    for (int i = 1; i < n; i++) {
        int x; scanf("%d", &x);
        sm += x - 1;
    }
    printf("%d\n", (K - sm % n + n) % n + 1);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
