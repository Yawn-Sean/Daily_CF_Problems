#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, int MOD) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    int n, m, a, Q; scanf("%d%d%d%d", &n, &m, &a, &Q);
    
    long long p = 1;
    int phi = 0;
    while (true) {
        p = p * a % Q;
        phi++;
        if (p == 1) break;
    }

    long long sm = 0, now = 1;
    vector<long long> ans;
    for (int i = 1; i <= n; i++) {
        sm = (sm + now) % phi;
        now = now * (m - (i - 1)) % phi;
        now = now * power(i, phi - 2, phi) % phi;
        ans.push_back(power(a, sm, Q));
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) printf("%lld%c", ans[i], "\n "[i + 1 < n]);
    return 0;
}
