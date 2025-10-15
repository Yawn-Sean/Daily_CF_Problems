#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1E9;

template <typename T>
bool chmin(T &a, const T &b) {
    return b < a ? a = b, true : false;
}
template <typename T>
bool chmax(T &a, const T &b) {
    return b > a ? a = b, true : false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    int s = 0;
    int ans = inf;
    int cnt = std::ranges::count(b, 0);
    std::vector<int> cur(m);

    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && cnt != m) {
            int x = a[j];
            cur[x]++;
            s += (cur[x] > b[x]);
            cnt += (cur[x] == b[x]);
            j++;
        }
        if (cnt == m) {
            chmin(ans, s);
        }
        s -= (cur[a[i]] > b[a[i]]);
        cur[a[i]]--;
        cnt -= (cur[a[i]] == b[a[i]] - 1);
    }

    if (ans == inf) {
        std::cout << -1 << "\n";
    } else {
        std::cout << ans << "\n";
    }

    return 0;
}
