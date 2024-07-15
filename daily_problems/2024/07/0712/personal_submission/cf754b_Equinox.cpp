#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
using PIII = std::pair<int, PII>;
const int inf = 1e9 + 7, P = 1e9 + 7;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::array<int, 3>> segs(n);
    
    for (int i = 0; i < n; ++ i)
        std::cin >> segs[i][0] >> segs[i][1], segs[i][2] = i + 1;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    std::sort(segs.begin(), segs.end(), [](auto& x, auto& y) {
        return x[0] < y[0];
    });

    int res = -1, st = -1;

    for (auto& [l, r, id] : segs) {
        pq.emplace(r);
        if (pq.size() == k + 1) pq.pop();
        if (pq.size() == k && pq.top() - l > res)
            st = l, res = pq.top() - l;
    }

    if (res == -1) {
        std::cout << 0 << '\n';
        for (int i = 1; i <= k; ++ i) std::cout << i << " \n"[i == k];
    }
    else{
        std::cout << res + 1 << '\n';
        for (auto& [l, r, id] : segs)
            if (k && l <= st && r >= st + res)
                std::cout << id << " \n"[-- k == 0];
    }
}


int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}