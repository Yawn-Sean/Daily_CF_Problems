// 0507
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    i64 n;
    std::cin >> n;
    string command;
    cin >> command;
    int cmd_len = ssize(command);

    int x = 0;
    int y = 0;
    int x_start = -1;
    int y_start = -1;
    for (int i = 0; i < cmd_len; ++i) {
        if (x_start == -1 && command[i] != command[0]) {
            x_start = x;
            y_start = y;
        }

        if (command[i] == 'R') {
            ++y;
        } else {
            ++x;
        }
    }

    if (x == 0 || y == 0) {
        cout << n << endl;
        return;
    }

    const auto prev_path_len = x_start + y_start;
    cout << prev_path_len + n * (n - prev_path_len) - (x - x_start) * (y - y_start) << endl;
    return;
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