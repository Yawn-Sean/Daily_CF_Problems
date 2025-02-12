#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> m(n);
    for (auto& x : m) {
        scanf("%d", &x);
    }
    vector<int> t(n, 0);
    t[0] = 1;
    for (int i = 1; i < n; i++) {
        // t[i] >= m[i] + 1
        // t[i] >= t[i - 1]
        t[i] = max(m[i] + 1, t[i - 1]);
    }
    long long ans = t[n - 1] - m[n - 1] - 1;
    for (int i = n - 2; i >= 0; i--) {
        t[i] = max(t[i], t[i + 1] - 1);
        ans += t[i] - m[i] - 1;
    }
    printf("%lld\n", ans);
    return 0;
}

