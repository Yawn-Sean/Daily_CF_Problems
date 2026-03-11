#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int N = 2e5;
constexpr int INF = 2e9;
int64 a[N], b[N + 1];

int main() {
    int n;
    int64 s;
    scanf("%d %lld", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i - 1];
    }
    int num = *ranges::partition_point(views::iota(0, INF), [&] (int x) -> bool {
        int64 sum = 1LL * (x + 1) * x / 2;
        int i = upper_bound(a, a + n, x) - a;
        sum += b[n] - b[i];
        return sum < s;
    });
    printf("%d\n", num + n - (upper_bound(a, a + n, num) - a));
    return 0;
}

