#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
vector<int> rs[N];
vector<int> a[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, s, r; i < n; i++) {
        scanf("%d%d", &s, &r);
        rs[s - 1].push_back(r);
    }
    for (int i = 0; i < m; i++) {
        if (rs[i].empty()) continue;
        ranges::sort(rs[i], greater<int>());
        int k = rs[i].size();
        a[0].push_back(rs[i][0]);
        for (int j = 1; j < k; j++) {
            rs[i][j] += rs[i][j - 1];
            a[j].push_back(rs[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ranges::sort(a[i], greater<int>());
        int cur = 0;
        for (auto& x : a[i]) {
            if (x < 0) break;
            cur += x;
        }
        ans = max(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}

