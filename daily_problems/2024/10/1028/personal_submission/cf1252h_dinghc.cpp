#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    long long ans = 0;
    for (auto& [l, w] : a) {
        scanf("%d%d", &l, &w);
        if (l > w) swap(l, w);
        ans = max(ans, 1LL * l * w);
    }
    ranges::sort(a);
    int wx = a[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        auto& [l, w] = a[i];
        ans = max(ans, 1LL * l * min(w, wx) * 2);
        wx = max(wx, w);
    }
    printf("%lld", ans / 2);
    printf(".%d\n", ans % 2 == 1 ? 5 : 0);
    return 0;
}

