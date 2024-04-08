#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    string input;
    cin >> input;
    int bitmask = 0;
    for (auto ch : input) {
        bitmask ^= (1 << (ch - '0'));
    }

    int len = size(input);
    for (int i = len - 1; i >= 0; --i) {
        bitmask ^= (1 << (input[i] - '0'));
        for (int j = input[i] - '0' - 1; j >= 0; --j) {
            if (i == 0 && j == 0) {
                break;
            }

            int new_bitmask = bitmask ^ (1 << j);
            int odd_count = __builtin_popcount(new_bitmask);
            if (odd_count <= len - 1 - i) {
                string tail{};
                for (int k = 9; k >= 0; --k) {
                    if ((new_bitmask >> k) & 1) {
                        tail += string(1, '0' + k);
                    }
                }

                string ret = input.substr(0, i) + string(1, '0' + j)
                             + string(len - 1 - i - odd_count, '9') + tail;
                cout << ret << endl;
                return;
            }
        }
    }
    cout << string((len / 2 - 1) * 2, '9') << endl;
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