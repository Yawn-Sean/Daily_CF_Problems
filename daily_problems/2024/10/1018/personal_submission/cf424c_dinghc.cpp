#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1'000'000;
int xors[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        ans ^= x;
        if ((n - i) % 2 == 1) ans ^= i;
    }
    for (int i = 1; i <= n; i++) {
        xors[i] = xors[i - 1] ^ i;
    }
    for (int m = 2; m <= n; m++) {
        int q = (n - m + 1) / m;
        int r = (n - m + 1) % m;
        if (r >= 1) ans ^= xors[r - 1];
        if (q % 2 == 1) ans ^= xors[m - 1];
    }
    printf("%d\n", ans);
    return 0;
}

