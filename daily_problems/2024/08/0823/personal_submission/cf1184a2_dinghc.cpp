#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200'000;
char a[N + 1];
int b[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", a);
    for (auto& x : a) x = x - '0';
    auto check = [&] (int d) -> int {
        for (int i = 0; i < d; i++) {
            int xors = 0;
            for (int j = i; j < n; j += d) {
                xors ^= a[j];
            }
            if (xors != 0) {
                return 0;
            }
        }
        return 1;
    };
    int r2 = *ranges::partition_point(views::iota(1, n + 1), [&] (int r) {
        return r * r < n;
    });
    for (int i = 1; i <= r2; i++) {
        if (n % i == 0) {
            b[i] = check(i);
            if (n / i != i) b[n / i] = check(n / i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (b[gcd(i, n)]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}

