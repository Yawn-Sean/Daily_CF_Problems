#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, K; scanf("%d%d", &n, &K);
    if (K % 3) {
        if (n % 3) printf("Alice\n");
        else printf("Bob\n");
    } else {
        n %= K + 1;
        if (n % 3 || n == K) printf("Alice\n");
        else printf("Bob\n");
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
