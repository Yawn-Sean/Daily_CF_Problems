#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <u32 Id>
Barrett DynModInt<Id>::bt = 1000000009;

using Z = DynModInt<0>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<bool> vis(n);

    using A = std::array<int, 2>;
    std::vector<A> a(n);
    std::map<A, int> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
        mp[a[i]] = i;
    }

    auto check = [&](int x, int y) {
        for (int d = -1; d <= 1; d++) {
            if (mp.contains({x + d, y + 1})) {
                bool ok = false;
                for (int v = -1; v <= 1; v++) {
                    if (d + v == 0) continue;
                    if (mp.contains({x + d + v, y})) {
                        ok = true;
                    }
                }
                if (!ok) return false;
            }
        }
        return true;
    };

    std::priority_queue<int> max;
    std::priority_queue<int, std::vector<int>, std::greater<>> min;
    for (int i = 0; i < n; i++) {
        if (check(a[i][0], a[i][1])) {
            max.push(i);
            min.push(i);
        }
    }

    auto add = [&](A point) {
        auto [x, y] = point;
        for (int i = -1; i <= 1; i++) {
            if (mp.contains({x - i, y - 1}) && check(x - i, y - 1)) {
                max.push(mp[{x - i, y - 1}]);
                min.push(mp[{x - i, y - 1}]);
            }
        }
    };

    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {  // maxHeap
            vec[i] = max.top();
            max.pop();
        } else {  // minHeap
            vec[i] = min.top();
            min.pop();
        }
        if (vis[vec[i]] || !check(a[vec[i]][0], a[vec[i]][1])) {
            i--;
            continue;
        }
        vis[vec[i]] = true;
        mp.extract(a[vec[i]]);
        add(a[vec[i]]);
    }

    Z ans = 0, base = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans += vec[i] * base;
        base *= n;
    }
    std::cout << ans << "\n";

    return 0;
}
