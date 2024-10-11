#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> h(n), w(n);
    for (int i = 0; i < n; ++ i) {
        std::cin >> h[i] >> w[i];
        if (h[i] > w[i]) 
            std::swap(h[i], w[i]);
    }

    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);
    std::ranges::sort(id, [&](int i, int j){
        if (h[i] != h[j]) return h[i] < h[j];
        return w[i] > w[j];
    });

    std::vector<int> ans(n, -1);

    std::vector<int> lis{id[0]};

    for (int i = 1; i < n; ++ i) {
        if (w[id[i]] > w[lis.back()]) {
            ans[id[i]] = lis.back() + 1;
            lis.push_back(id[i]);
            continue;
        }

        int b = std::lower_bound(lis.begin(), lis.end(), id[i], [&](int x, int y){
            return w[x] < w[y];
        }) - lis.begin();
        // std::cerr << i << ' ' << b << '\n';
        if (b) {
            ans[id[i]] = lis[b - 1] + 1;
        }
        lis[b] = id[i];
    }

    // for (int x : lis) std::cerr << x << ' '; 

    for (int i = 0; i < n; ++ i)
        std::cout << ans[i] << " \n"[i + 1 == n];
    // exit(0);

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}