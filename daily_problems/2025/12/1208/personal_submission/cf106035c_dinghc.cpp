#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100;
using bigint = bitset<N>;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    if (n == m) {
        printf("1\n");
        return 0;
    }
    auto add = [] (bigint a, bigint b) -> bigint {
        bigint c{};
        bool carry = false;
        for (int i = 0; i < N; i++) {
            auto x = a[i] ^ b[i];
            auto y = a[i] & b[i];
            auto z = x ^ carry;
            y |= x & carry;
            carry = y;
            c[i] = z;
        }
        return c;
    };
    vector<bigint> combs{1, 1};
    for (int i = 2; i <= k; i++) {
        vector<bigint> ncombs(i + 1);
        ncombs[0] = ncombs[i] = 1;
        for (int j = 1; j < i; j++) {
            ncombs[j] = add(combs[j - 1], combs[j]);
        }
        combs.swap(ncombs);
    }
    int ans = 0;
    int x = abs(n - m);
    bigint msk{};
    msk.set();
    if (x < N) msk >>= N - x;
    bigint carry{};
    for (int i = 0; i <= k; i++) {
        auto cur = add(combs[i], carry);
        if (x < N) {
            carry = cur >> x;
        }
        cur &= msk;
        ans += cur.count();
    }
    printf("%d\n", ans + carry.count());
    return 0;
}

