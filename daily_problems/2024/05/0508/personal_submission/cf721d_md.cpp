// 0508
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    i64 k, x;
    std::cin >> n >> k >> x;
    vector<i64> a(n);

    auto dump_a = [&]() {
        for (auto i = 0; i < size(a); ++i) {
            cout << a[i] << " \n"[i == size(a) - 1];
        }
    };

    array<int, 3> cnts{0};
    optional<int> max_neg_id = std::nullopt;
    optional<int> min_pos_id = std::nullopt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            cnts[0]++;
            if (!max_neg_id.has_value() || a[i] > a[max_neg_id.value()]) {
                max_neg_id = i;
            }
        } else if (a[i] == 0) {
            cnts[1]++;
        } else {
            cnts[2]++;
            if (!min_pos_id.has_value() || a[i] < a[min_pos_id.value()]) {
                min_pos_id = i;
            }
        }
    }

    // number of zero > 0
    if (cnts[1] > 0) {
        if (k < cnts[1]) {
            // product == 0
            a[0] -= k * x;
            dump_a();
            return 0;
        } else {
            for (int i = 0; i < n; ++i) {
                if (a[i] == 0) {
                    if (cnts[0] & 1) {
                        a[i] += x;
                        cnts[2]++;
                    } else {
                        a[i] -= x;
                        cnts[0]++;
                    }
                    cnts[1]--;
                    k--;
                }
            }
        }
    }

    // even number of negative numbers
    if ((cnts[0] & 1) == 0) {
        auto max_neg_val = max_neg_id.has_value() ? a[max_neg_id.value()] : numeric_limits<i64>::max();
        auto min_pos_val = min_pos_id.has_value() ? a[min_pos_id.value()] : numeric_limits<i64>::max();
        auto updateIdx = abs(max_neg_val) < abs(min_pos_val) ? max_neg_id.value() : min_pos_id.value();
        i64 diff = abs(a[updateIdx]);
        if (diff < k * x) {
            i64 ops = (diff + x - 1) / x;
            if (diff >= ops * x) {
                ops++;
            }
            if (a[updateIdx] < 0) {
                a[updateIdx] += ops * x;
            } else {
                a[updateIdx] -= ops * x;
            }
            k -= ops;
        } else {
            // positive product
            if (a[updateIdx] < 0) {
                a[updateIdx] += k * x;
            } else {
                a[updateIdx] -= k * x;
            }
            dump_a();
            return 0;
        }
    }

    // negative product
    priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> min_nums;
    for (int i = 0; i < n; ++i) {
        min_nums.push({abs(a[i]), i});
    }

    while (k > 0) {
        auto [val, idx] = min_nums.top();
        min_nums.pop();
        if (a[idx] >= 0) {
            a[idx] += x;
        } else {
            a[idx] -= x;
        }
        min_nums.push({abs(a[idx]), idx});
        k--;
    }

    dump_a();

    return 0;
}