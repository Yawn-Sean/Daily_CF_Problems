#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int64 n;
    scanf("%lld", &n);
    int64 f = *ranges::partition_point(ranges::iota_view(0LL, n + 1), [&] (int64 x) -> bool {
        return x <= n / x && x * x * 3 / 2 + x / 2 <= n;
    }) - 1;
    f -= (f + n) % 3; 
    printf("%lld\n", (f + 2) / 3);
    return 0;
}

