#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0LL;
    int mx = 0;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        sum += x;
        mx = max(mx, x);
    }
    if (mx > 2 * (sum - mx)) {
        printf("%lld\n", sum - mx);
    } else {
        printf("%lld\n", sum / 3);
    }
    return 0;
}

