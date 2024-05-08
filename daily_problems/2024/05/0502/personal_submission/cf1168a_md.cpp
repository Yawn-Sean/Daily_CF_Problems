// 0502
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

    auto cando = [&](int moves) -> bool {
        int prev = 0;
        for (auto num : a) {
            if (num >= prev) {
                // best effort to reduce num to prev.
                if (num + moves >= m && (num + moves) % m >= prev) {
                    continue;
                } else {
                    prev = num;
                }
            } else if (num + moves < prev) {
                // prev is already the min possible value.
                return false;
            }
        }
        return true;
    };

    int lo = 0;
    int hi = m;
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;
        if (cando(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (cando(lo)) {
        cout << lo << endl;
    } else {
        cout << hi << endl;
    }

    return 0;
}