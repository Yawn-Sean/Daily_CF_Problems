#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> d(n), r(n);
    for (auto& x : d) {
        cin >> x;
    }
    vector<array<int, 2>> rg;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        rg.push_back({max(0, i - r[i]), min(n - 1, i + r[i])});
    }

    rgs::sort(rg);

    auto check = [&](int mid) -> int {
        auto a = d;
        int cnt = 0, mx = 0, l = 0;
        vector<int> dif(n + 1);
        for (int i = 0; i < n; i++) {
            while (l < n && rg[l][0] <= i) {
                mx = max(mx, rg[l++][1]);
            }
            while (a[i] + dif[i] < mid && cnt < k) {
                dif[i]++, dif[mx + 1]--, cnt++;
            }

            if (a[i] + dif[i] < mid || cnt > k) {
                return 0;
            }

            dif[i + 1] += dif[i];
        }

        return 1;
    };

    i64 ans = 0;
    i64 l = 0, rr = 2e9;
    while (l <= rr) {
        i64 mid = (l + rr) >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            rr = mid - 1;
        }
    }

    cout << ans;
    return 0;
}