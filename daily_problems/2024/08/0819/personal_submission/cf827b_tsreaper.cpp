#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K; scanf("%d%d", &n, &K);
    int d = (n - 1) / K;
    if ((n - 1) % K >= 2) printf("%d\n", d * 2 + 2);
    else if ((n - 1) % K == 1) printf("%d\n", d * 2 + 1);
    else printf("%d\n", d * 2);
    for (int i = 1; i < n; i++) printf("%d %d\n", i, min(n, i + K));
    return 0;
}
