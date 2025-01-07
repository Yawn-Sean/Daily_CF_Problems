#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    vector<int> t(k);
    long long tot = 0;
    for (auto& x : t) {
        scanf("%d", &x);
        tot += x;
    }
    int ans = 0;
    if (m >= n * tot) {
        ans = n * (k + 1);
    } else {
        ranges::sort(t);
        for (int i = 0; i < n; i++) {
            int r = m - i * tot;
            if (r < 0) break;
            if ((n - i) * tot - (n - i - 1) * t[k - 1] > r) {
                int res = i * (k + 1);
                int j = 0;
                while (r && j < k) {
                    int p = min(n - i, r / t[j]);
                    r -= p * t[j++];
                    res += p;
                }
                ans = max(ans, res);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

