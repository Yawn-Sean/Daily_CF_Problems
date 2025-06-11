#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K; scanf("%d%d", &n, &K);
    long long ans = 1;
    if (K >= 2) ans += 1LL * n * (n - 1) / 2;
    if (K >= 3) ans += 1LL * n * (n - 1) * (n - 2) / 6 * 2;
    if (K >= 4) {
        vector<int> vec;
        for (int i = 0; i < 4; i++) vec.push_back(i);
        int cnt = 0;
        for (int t = 0; t < 24; t++) {
            bool ok = true;
            for (int i = 0; i < 4; i++) if (vec[i] == i) { ok = false; break; }
            if (ok) cnt++;
            next_permutation(vec.begin(), vec.end());
        }
        ans += 1LL * n * (n - 1) * (n - 2) * (n - 3) / 24 * cnt;
    }
    printf("%lld\n", ans);
    return 0;
}
