#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int pw[7];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pw[0] = 1;
    for (int i = 1; i <= 6; i++) {
        pw[i] = pw[i - 1] * 10;
    }

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        i64 k;
        cin >> a >> b >> c >> k;
        bool find = false;
        int mn_a = pw[a - 1];
        int mx_a = pw[a] - 1;

        int mn_b = pw[b - 1];
        int mx_b = pw[b] - 1;
        for (int i = mn_a; i <= mx_a; i++) {
            int x = i + mn_b;
            int y = i + mx_b;

            int mn_c = pw[c - 1];
            int mx_c = pw[c] - 1;
            if (x > mx_c || y < mn_c) {
                continue;
            }

            i64 num = min(mx_c, y) - max(mn_c, x) + 1;
            num = max(num, 0ll);
            if (k > num) {
                k -= num;
            } else {
                find = true;
                int target_c = max(mn_c, x) + k - 1;
                cout << i << " + " << target_c - i << " = " << target_c << '\n';
                break;
            }
        }

        if (!find) {
            cout << -1 << '\n';
        }
    }

    return 0;
}
