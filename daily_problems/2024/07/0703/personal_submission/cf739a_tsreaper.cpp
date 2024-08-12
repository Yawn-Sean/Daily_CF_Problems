#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    int mn = n;
    for (int i = 1; i <= m; i++) {
        int l, r; scanf("%d%d", &l, &r);
        mn = min(mn, r - l + 1);
    }
    printf("%d\n", mn);
    for (int i = 1; i <= n; i++) printf("%d%c", i % mn, "\n "[i < n]);
    return 0;
}
