//0502
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; i64 T;
    std::cin >> n >> T;
    vector<i64> a(n), t(n);
    copy_n(istream_iterator<i64>(cin), n, begin(a));
    copy_n(istream_iterator<i64>(cin), n, begin(t));
    transform(begin(t), end(t), begin(t), [T](i64 x) { return x - T; });
    
    i64 amt{ 0ll };
    vector<pair<i64, i64>> pos, neg;
    for (int i = 0; i < n; ++i) {
        if (t[i] > 0) {
            pos.emplace_back(t[i], a[i]);
        } else if (t[i] < 0) {
            neg.emplace_back(-t[i], a[i]);
        } else {
            amt += a[i];
        }
    }

    i64 pos_sum = accumulate(begin(pos), end(pos), 0ll, [](i64 acc, pair<i64, i64> p) { return acc + p.first * p.second; });
    i64 neg_sum = accumulate(begin(neg), end(neg), 0ll, [](i64 acc, pair<i64, i64> p) { return acc + p.first * p.second; });
    
    auto calculate = [&](vector<pair<i64, i64>>& values, const i64 max_sum) -> double {
        sort(begin(values), end(values));
        i64 cur_sum = 0ll;
        for (auto[t, a] : values) {
            i64 tmp = 1ll * t * a;
            if (cur_sum + tmp < max_sum) {
                cur_sum += tmp;
                amt += a;
            } else {
                return 1.0 * (max_sum - cur_sum) / t;
            }
        }
        return 0.0;
    };

    double residual = 0.0;
    if (pos_sum < neg_sum) {
        amt += accumulate(begin(pos), end(pos), 0ll, [](i64 acc, pair<i64, i64> p) { return acc + p.second; });
        residual = calculate(neg, pos_sum);
    } else {
        amt += accumulate(begin(neg), end(neg), 0ll, [](i64 acc, pair<i64, i64> p) { return acc + p.second; });
        residual = calculate(pos, neg_sum);
    }

    cout << fixed << setprecision(15) << amt + residual << '\n';
    return 0;
}