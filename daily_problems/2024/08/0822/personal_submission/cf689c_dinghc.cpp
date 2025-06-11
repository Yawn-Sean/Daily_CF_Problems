#include <bits/stdc++.h>

using namespace std;
using li = long long;

int main() {
    li m;
    scanf("%lld", &m);
    auto count_ways = [] (li n) -> li {
        li r3 = *ranges::partition_point(views::iota(1LL, n + 1), [&] (li r) {
            return r <= (n / r) / r;
        });
        li cnt = 0LL;
        for (li i = 2; i <= r3; i++) {
            cnt += n / (1LL * i * i * i);
        }
        return cnt;
    };
    li lo = 1LL, hi = 5e15;
    while (lo <= hi) {
        li n = (hi + lo) / 2;
        if (count_ways(n) >= m) {
            hi = n - 1;
        } else {
            lo = n + 1;
        }
    }
    if (count_ways(lo) == m) {
        printf("%lld\n", lo);
    } else {
        printf("-1\n");
    }
    return 0;
}

