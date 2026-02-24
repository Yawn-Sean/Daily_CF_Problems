#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        long long n;
        scanf("%lld", &n);
        auto x = *ranges::partition_point(ranges::iota_view(0LL, n + 1), [&] (long long x) -> bool {
            long long y = x;
            long long sum = 0;
            while (x) {
                sum += x;
                x /= 10;
            }
            return sum <= n;
        });
        printf("%lld\n", n - x + 1);
    }
    return 0;
}

