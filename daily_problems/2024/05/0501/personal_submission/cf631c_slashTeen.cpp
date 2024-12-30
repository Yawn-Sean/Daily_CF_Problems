#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<pair<int, int>> ops; // vector 模拟 stack
    for (int i = 0; i < m; ++i) {
        int t, r;
        cin >> t >> r;

        while (!ops.empty() && ops.back().second <= r) {
            ops.pop_back();
        }
        ops.emplace_back(t, r);
    }

    vector<int> res(vec.begin(), vec.begin() + ops[0].second); // the biggest scope
    ranges::sort(res);
    int p = 0, q = ops[0].second - 1;
    ops.emplace_back(0, 0); // 哨兵
    for (int i = 0; i < ops.size() - 1; ++i) {
        for (int j = ops[i].second; j > ops[i + 1].second; --j) { // 在已定范围内操作，不影响后续小范围
            vec[j - 1] = res[ops[i].first == 1 ? q-- : p++];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << vec[i] << " \n"[i == n - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
