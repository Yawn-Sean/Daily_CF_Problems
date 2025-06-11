#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> s(n);
    for (auto& x : s) {
        scanf("%lld", &x);
    }
    ranges::sort(s);
    for (int i = 1; i < n; i++) {
        s[i - 1] = s[i] - s[i - 1];
    }
    s[n - 1] = LONG_LONG_MAX;
    ranges::sort(s);
    vector<long long> pre(n + 1, 0LL);
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + s[i - 1];
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        long long w = r - l + 1;
        int j = ranges::upper_bound(s, w) - s.begin();
        printf("%lld ", pre[j] + w * (n - j));
    }
    return 0;
}

