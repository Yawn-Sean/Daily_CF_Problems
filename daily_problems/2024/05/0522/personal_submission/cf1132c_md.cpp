// 0522
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; int q;
    std::cin >> n >> q;

    vector<pair<int, int>> queries;
    queries.reserve(q);
    vector<int> sections(n);

    auto fill_sections = [&](int l, int r, int delta) {
        for (int p = l; p <= r; ++p) {
            sections[p] += delta;
        }
    };

    for (int i = 0; i < q; ++i) {
        int l; int r;
        cin >> l >> r;
        --l; --r;
        queries.emplace_back(l, r);
        fill_sections(l, r, 1);
    }

    int ret = 0;
    for (int i = 0; i < q; ++i) {
        auto[l, r] = queries[i];
        fill_sections(l, r, -1);
        
        int walls = count_if(begin(sections), end(sections), [](int x) { return x >= 1; });
        
        vector<int> prefix(n + 1);
        transform(begin(sections), end(sections), next(begin(prefix)), [](int x) { return x == 1; });
        partial_sum(begin(prefix), end(prefix), begin(prefix));
        
        for (int j = 0; j < i; ++j) {
            auto[l2, r2] = queries[j];
            ret = max(ret, walls - (prefix[r2 + 1] - prefix[l2]));
        }

        fill_sections(l, r, 1);
    }

    cout << ret << endl;
    return 0;
}