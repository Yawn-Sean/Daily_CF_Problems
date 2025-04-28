#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) {
        scanf("%d%d", &x, &y);
    }
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    ranges::sort(indices, [&] (int i, int j) {
        auto& [x_i, y_i] = a[i];
        auto& [x_j, y_j] = a[j];
        int64 d_i = 1LL * (x_i - x1) * (x_i - x1) + 1LL * (y_i - y1) * (y_i - y1);
        int64 d_j = 1LL * (x_j - x1) * (x_j - x1) + 1LL * (y_j - y1) * (y_j - y1);
        return d_i < d_j;
    });
    multiset<int64> q{0LL};
    for (auto& [x, y] : a) {
        q.emplace(1LL * (x - x2) * (x - x2) + 1LL * (y - y2) * (y - y2));
    }
    int64 ans = *q.rbegin();
    for (int i = 0; i < n; i++) {
        auto& [x, y] = a[indices[i]];
        int64 d1 = 1LL * (x - x1) * (x - x1) + 1LL * (y - y1) * (y - y1);
        int64 d2 = 1LL * (x - x2) * (x - x2) + 1LL * (y - y2) * (y - y2);
        q.erase(q.find(d2));
        ans = min(ans, d1 + *q.rbegin());
    }
    printf("%lld\n",  ans);
    return 0;
}

