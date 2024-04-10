#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, m;
    std::cin >> n >> m;

    vector<i64> a(n);
    vector<i64> b(m);
    copy_n(istream_iterator<i64>(std::cin), n, begin(a));
    copy_n(istream_iterator<i64>(std::cin), m, begin(b));
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    
    if (a[0] >= b.back()) {
        cout << 0 << endl;
        return 0;
    }

    vector<i64> sum_a(n + 1);
    partial_sum(begin(a), end(a), next(begin(sum_a)));
    vector<i64> sum_b(m + 1);
    partial_sum(begin(b), end(b), next(begin(sum_b)));

    i64 ret = LLONG_MAX;
    set<i64> s;
    copy(begin(a), end(a), inserter(s, begin(s)));
    copy(begin(b), end(b), inserter(s, begin(s)));
    for (auto x : s) {
        auto pos_a = upper_bound(begin(a), end(a), x) - begin(a);
        auto pos_b = upper_bound(begin(b), end(b), x) - begin(b);
        ret = min(ret, 1ll * x * pos_a - sum_a[pos_a] + sum_b[m] - sum_b[pos_b] - 1ll * (m - pos_b) * x); 
    }

    cout << ret << endl;
    return 0;
}