#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; scanf("%lld", &n);
    int ans = 0;
    for (int i = 1; ; i++) {
        long long base = 2LL * i;
        base += 3LL * (i - 1) * i / 2;
        if (base > n) break;
        if ((n - base) % 3 == 0) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
