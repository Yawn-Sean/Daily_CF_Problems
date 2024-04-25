#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        --f[i];
    }

    vector<int> fixed_point;    
    for (int i = 0; i < n; ++i) {
        if (f[i] != f[f[i]]) {
            cout << -1 << endl;
            return 0;
        }
        if (f[i] == i) {
            fixed_point.push_back(i);
        }
    }

    auto m = size(fixed_point);
    vector<int> g(n), h(m);
    for (int i = 0; i < n; ++i) {
        g[i] = lower_bound(begin(fixed_point), end(fixed_point), f[i]) - begin(fixed_point);
        if (f[i] == i) {
            h[g[i]] = i;
        }
    }

    transform(begin(g), end(g), begin(g), [](int x) { return x + 1; });
    transform(begin(h), end(h), begin(h), [](int x) { return x + 1; });

    cout << m << endl;
    copy_n(begin(g), n, ostream_iterator<int>(cout, " "));
    cout << endl;
    copy_n(begin(h), m, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}