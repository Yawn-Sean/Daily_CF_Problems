#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, A, cf, cm;
    i64 m;
    std::cin >> n >> A >> cf >> cm >> m;

    std::vector<int> a(n);
    copy_n(istream_iterator<int>(std::cin), n, begin(a));

    vector<int> ids(n);
    iota(begin(ids), end(ids), 0);
    sort(begin(ids), end(ids), [&](int i, int j) { return a[i] < a[j]; });

    std::vector<i64> sums(n + 1);
    for (int i = 0; i < n; ++i) {
        sums[i + 1] = sums[i] + a[ids[i]];
    }

    i64 final_full = 0;
    i64 final_min = 0;

    auto get_residual = [&] (int cnt, i64 total) -> i64 {
        return total - (1ll * cnt * a[ids[cnt - 1]] - sums[cnt]);
    };

    auto update_final = [&] (i64 full, i64 new_min) {
        if (new_min * cm + full * cf >= final_full * cf + final_min * cm) {
            final_full = full;
            final_min = new_min;
        }
    };

    for (int full = 0; full <= n; ++full) {
        i64 need = 1ll * full * A - (sums[n] - sums[n - full]);
        if (need > m) {
            break;
        }

        if (full == n) {
            update_final(full, A);
            break;
        }

        i64 total = m - need;
        int lo = 1;
        int hi = n - full;
        while (lo + 1 < hi) {
            auto mid = lo + (hi - lo) / 2;
            if (get_residual(mid, total) < 0) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        int min_num_cnt = lo;
        if (get_residual(hi, total) >= 0) {
            min_num_cnt = hi;
        }

        int overflow = get_residual(min_num_cnt, total) / min_num_cnt;
        int new_min = min(A, a[ids[min_num_cnt - 1]] + overflow);
        update_final(full, new_min);
    }
    
    for (auto& num : a) {
        num = max((i64)num, final_min);
    }

    for (int i = 0; i < final_full; ++i) {
        a[ids[n - 1 - i]] = A;
    }

    // cerr << final_full << ' ' << final_min << '\n';

    cout << final_full * cf + final_min * cm << '\n';
    for (auto num : a) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}