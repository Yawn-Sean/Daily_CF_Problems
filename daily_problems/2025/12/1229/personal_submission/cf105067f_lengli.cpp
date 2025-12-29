#include <bits/stdc++.h>
using namespace std;

static inline long long floor_div(long long a, long long b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return a / b;
    return - ((-a + b - 1) / b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int cnt[2][17] = {};

    for (int x : a) {
        for (int b = 0; b < 17; b++) {
            cnt[(x >> b) & 1][b]++;
        }
    }

    const int B = 17;
    const int M = 1 << B;

    vector<long long> vals(M);

    for (int mask = 0; mask < M; mask++) {
        long long sum = 0;
        for (int b = 0; b < B; b++) {
            int bit = (mask >> b) & 1;
            sum += (1LL << b) * cnt[bit ^ 1][b];
        }
        vals[mask] = sum;
    }

    sort(vals.begin(), vals.end());

    long long period = 1LL * M * n;
    long long ans = 0;

    for (int i = 0; i < M; i++) {
        if (i == 0 || vals[i] != vals[i - 1]) {
            ans += floor_div(r - vals[i], period)
                 - floor_div(l - 1 - vals[i], period);
        }
    }

    cout << ans << '\n';
    return 0;
}
