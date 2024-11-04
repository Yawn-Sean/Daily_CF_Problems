#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; scanf("%lld", &n);
    long long a = 1, b = 2;
    int ans, now = 1;
    while (b <= n) {
        ans = now;
        long long c = a + b;
        a = b; b = c;
        now++;
    }
    printf("%d\n", ans);
    return 0;
}
