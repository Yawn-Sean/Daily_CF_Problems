#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
    }

    function<int(int)> f = [&](int idx) {
        vector<int> a(n + 2);
        for (int i = 0; i < q; ++i) if (i != idx) {
            int x = l[i], y = r[i];
            a[x] += 1;
            a[y + 1] -= 1;
        }
        // 差分数组 -> 每个 sec 的工人
        int sm = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] += a[i - 1];
            sm += (a[i] >= 1);
        }
        // 只记录只有一个工人的 sec，前缀和处理
        for (int i = 1; i <= n; ++i) {
            a[i] = a[i] == 1 ? 1 : 0;
            a[i] += a[i - 1];
        }
        int ans = n;
        for (int i = idx + 1; i < q; ++i) {
            int x = l[i], y = r[i];
            ans = min(ans, a[y] - a[x - 1]);
        }
        return sm - ans;
    };
    
    int ans = 0;
    for (int i = 0; i < q - 1; ++i) {
        ans = max(ans, f(i));
    }
    cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}