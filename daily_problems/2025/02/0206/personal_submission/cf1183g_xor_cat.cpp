#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::array<int, 2>> c(n);
    for (int i = 0; i < n; i++) {
        int a, f;
        std::cin >> a >> f;
        a--;
        c[a][f]++;
    }

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::ranges::sort(p, [&](int x, int y) {
        return c[x][0] + c[x][1] > c[y][0] + c[y][1];
    });

    std::priority_queue<int> pq;
    int cur = 0;
    int ans1 = 0, ans2 = 0;
    for (int i = n; i > 0; i--) {
        while (cur < n && c[p[cur]][0] + c[p[cur]][1] >= i) {
            pq.push(c[p[cur]][1]);
            cur++;
        }
        if (!pq.empty()) {
            ans1 += i;
            ans2 += std::min(i, pq.top());
            pq.pop();
        }
    }

    std::cout << ans1 << " " << ans2 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
       solve();
    }

    return 0;
}
