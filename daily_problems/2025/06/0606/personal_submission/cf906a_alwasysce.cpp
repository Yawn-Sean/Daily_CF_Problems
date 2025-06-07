#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    // 可能的候选集合
    int mask = (1ll << 26) - 1;
    auto check = [&]() {
        return __builtin_popcount(mask) == 1;
    };

    int ans = 0;
    while (n--) {
        char op;
        cin >> op;
        string content;
        cin >> content;

        if (op == '.') {
            // 这些一定排除
            for (auto&ch: content) {
                mask &= ~(1 << (ch - 'a'));
            }
        } else if (op == '!') {
            ans += check();
            // 只有在content内出现的"才有可能"
            int cur_mask = 0;
            for (auto&ch: content) {
                cur_mask |= (1 << (ch - 'a'));
            }
            mask &= cur_mask;
        } else {
            if (n != 0) {
                ans += check();
            }
            for (auto&ch: content) {
                mask &= ~(1 << (ch - 'a'));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
