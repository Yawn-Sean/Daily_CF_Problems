#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    vector<int> nums(n);
    for (int i = 0, m, t; i < n; i++) {
        scanf("%d%d", &m, &t);
        nums[i] = m * b - a * t;
    }
    map<int64, int> cnt;
    int m = n / 2;
    for (int msk = 0; msk < (1 << m); msk++) {
        int64 tot = 0;
        for (int i = 0; i < m; i++) if (msk >> i & 1) {
            tot += nums[i];
        }
        cnt[tot] += 1;
    }
    int64 ans = 0;
    int k = n - m;
    for (int msk = 0; msk < (1 << k); msk++) {
        int64 tot = 0;
        for (int i = 0; i < k; i++) if (msk >> i & 1) {
            tot += nums[i + m];
        }
        if (cnt.find(-tot) != cnt.end()) {
            ans += cnt[-tot];
        }
    }
    printf("%lld\n", ans - 1);
    return 0;
}

