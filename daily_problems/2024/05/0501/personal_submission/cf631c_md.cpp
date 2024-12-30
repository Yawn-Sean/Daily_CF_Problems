// 0501
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    vector<int> a(n);
    copy_n(istream_iterator<int>(cin), n, begin(a));

    vector<pii> ops;
    for (int i = 0; i < m; ++i) {
        int t, r;
        cin >> t >> r;

        while (!empty(ops) && ops.back().second <= r) {
            ops.pop_back();
        }
        ops.emplace_back(t, r);
    }

    auto[t_0, r_0] = ops[0];
    int l = 0;
    int r = r_0 - 1;
    vector<int> sorted{begin(a), begin(a) + r_0};
    if (t_0 == 1) {
        sort(begin(sorted), end(sorted));
    } else {
        sort(begin(sorted), end(sorted), greater<>());
    }
    
    ops.emplace_back(0, 0); // for the last operation.
    for (auto i = 1; i < size(ops); ++i) {
        auto[t_last, r_last] = ops[i - 1];
        auto[t_cur, r_cur] = ops[i];
        for (auto j = r_last - 1; j >= r_cur; --j) {
            if (t_last == t_0) {
                a[j] = sorted[r--];
            } else {
                a[j] = sorted[l++];
            }
        }
    }

    for (auto i = 0; i < size(a); ++i) {
        cout << a[i] << " \n"[i == size(a) - 1];
    }
    return 0;
}