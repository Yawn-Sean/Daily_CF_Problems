// 0521
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, p;
    std::cin >> n >> p;
    vector<int> cnt(n);
    map<pii, int> pair_cnt;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        ++cnt[x];
        ++cnt[y];
        
        if (x > y) {
            swap(x, y);
        }
        ++pair_cnt[{x, y}];
    }

    i64 ret = 0;
    for (auto[duo, val] : pair_cnt) {
        auto[x, y] = duo;
        if (cnt[x] + cnt[y] >= p && cnt[x] + cnt[y] - val < p) {
            --ret;
        }
    }

    sort(begin(cnt), end(cnt));
    int start = 0;
    for (int end = n - 1; end >= 0; --end) {
        while (start < end && cnt[start] + cnt[end] < p) {
            ++start;
        }

        if (start < end) {
            ret += end - start;
        }
    }

    cout << ret << endl;

    return 0;
}