#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<i64> stones(n);
    copy_n(istream_iterator<i64>(cin), n, begin(stones));

    sort(begin(stones), end(stones), greater<>());
    partial_sum(begin(stones), end(stones), begin(stones));

    vector<i64> queries(1e5 + 1);
    for (i64 i = 1; i <= 1e5; ++i) {
        i64 weight = 1;
        for (i64 idx = 0, len = i; idx < n; idx += len, len *= i) {
            queries[i] += (0ll + stones[min(idx + len, static_cast<i64>(n - 1))] - stones[idx]) * weight;
            ++weight;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << queries[min(x, n)] << ' ';
    }
    cout << endl;

    return 0;
}