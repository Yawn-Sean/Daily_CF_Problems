#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 1e9+7;

int main() {
    int n;
    scanf("%d", &n);
    int r = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            b = (b + r + 1) % MOD;
        } else {
            r = (r + b + 1) % MOD;
        }
    }
    printf("%d\n", (r + b) % MOD);
    return 0;
}
