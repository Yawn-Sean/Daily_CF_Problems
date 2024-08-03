#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<string> inputs(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
    }

    vector<i64> cnt_s_of_str(n);
    vector<i64> cnt_h_of_str(n);
    for (int i = 0; i < n; ++i) {
        cnt_s_of_str[i] = count(begin(inputs[i]), end(inputs[i]), 's');
        cnt_h_of_str[i] = count(begin(inputs[i]), end(inputs[i]), 'h');
    }

    vector<int> ids(n);
    iota(begin(ids), end(ids), 0);
    sort(begin(ids), end(ids), [&](int i, int j) {
        // C_i + C_j + C_si * C_hj > C_j + C_i + C_sj * C_hi
        return cnt_s_of_str[i] * cnt_h_of_str[j] > cnt_s_of_str[j] * cnt_h_of_str[i];
    });

    i64 ret = 0;
    i64 cnt_s = 0;
    for (auto id : ids) {
        for (auto ch : inputs[id]) {
            if (ch == 's') {
                ++cnt_s;
            } else {
                ret += cnt_s;
            }
        }
    }

    cout << ret << endl;

    return 0;
}