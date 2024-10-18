#include <bits/stdc++.h>
#include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1e9 + 7;
constexpr i64 inf64 = 1e18 + 7;

/*
    前缀和+二分
*/

void solve() {
    int n, h;
    std::cin >> n >> h;
    std::vector<std::pair<int, int>> segs(n);
    for (int i = 0; i < n; ++ i) {
        std::cin >> segs[i].first >> segs[i].second;
    }
    std::ranges::sort(segs);
    std::vector<int> acc(n);
    for (int i = 1; i < n; ++ i) 
        acc[i] = acc[i - 1] + segs[i].first - segs[i - 1].second;
    int res = 0;;
    for (int i = 0; i < n; ++ i) {
        int lo = i, hi = n - 1, ans = -1;
        while (lo <= hi){
            int x = lo + hi >> 1;
            if (acc[x] - acc[i] < h)
                ans = x, lo = x + 1;
            else
                hi = x - 1;
        }
        if (~ans) {
            int nx = segs[ans].second + h - acc[ans] + acc[i];
            res = std::max(res, nx - segs[i].first);
        }
    }
    std::cout << res;
}

auto FIO = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}