// 0530
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    string s;
    std::cin >> s;
    int len = size(s);

    vector<int> leading_zeros(len);
    int last_zeros = s[0] == '0' ? 1 : 0;
    for (int i = 1; i < len; ++i) {
        leading_zeros[i] = last_zeros;
        if (s[i] == '0') {
            ++last_zeros;
        } else {
            last_zeros = 0;
        }
    }

    constexpr int max_digit_len = __lg(200000) + 1;
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '0') {
            continue;
        }

        int val = 0;
        for (int j = i; j < len && j - i + 1 <= max_digit_len; ++j) {
            val = val * 2 + s[j] - '0';
            if (j - i + 1 + leading_zeros[i] >= val) {
                ++ret;
            }
        }
    }

    cout << ret << endl;

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}