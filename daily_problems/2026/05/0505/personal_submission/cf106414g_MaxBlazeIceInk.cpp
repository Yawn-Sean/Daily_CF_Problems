#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<array<pair<int, int>, 2>> pre(n + 2), suf(n + 2);

    map<int, int> freq;
    set<pair<int, int>> st; // {出现次数, 值}

    auto get_top_two = [&]() -> array<pair<int, int>, 2> {
        array<pair<int, int>, 2> res;

        if (st.empty()) {
            res[0] = res[1] = {0, INF};
            return res;
        }

        auto it = st.end();
        --it;
        res[0] = *it; // 最高频

        if (st.size() >= 2) {
            --it;
            res[1] = *it; // 次高频
        } else {
            res[1] = {0, INF};
        }

        return res;
    };

    // 前缀：记录每个位置的前两大不同值及其频次
    for (int i = 1; i <= n; i++) {
        int v = a[i];

        if (freq[v] > 0) st.erase({freq[v], v});
        freq[v]++;
        st.insert({freq[v], v});

        auto cur = get_top_two();
        pre[i][0] = cur[0];
        pre[i][1] = cur[1];
    }

    freq.clear();
    st.clear();

    // 后缀：记录每个位置的后两大不同值及其频次
    for (int i = n; i >= 1; i--) {
        int v = a[i];

        if (freq[v] > 0) st.erase({freq[v], v});
        freq[v]++;
        st.insert({freq[v], v});

        auto cur = get_top_two();
        suf[i][0] = cur[0];
        suf[i][1] = cur[1];
    }

    int ans = 0;

    // 枚举分割点，左边全为 A，右边全为 B，A != B
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                auto p = pre[i][j];
                auto q = suf[i + 1][k];

                if (p.second == INF || q.second == INF) continue;
                if (p.second == q.second) continue;

                ans = max(ans, p.first + q.first);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}