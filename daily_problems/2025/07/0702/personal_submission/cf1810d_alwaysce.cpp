#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        i64 h_min = -1e18, h_max = 1e18;

        auto f = [&](i64 x, i64 a, i64 b) -> i64 {
            if (x <= a) {
                return 1ll;
            }
            return 1ll * (x - a - 1) / (a - b) + 2;
        };

        while (q--) {
            int num;
            cin >> num;

            if (num == 1) {
                i64 a, b, n;
                cin >> a >> b >> n;

                i64 cur_min = 1ll * (n - 2) * (a - b) + a + 1;
                i64 cur_max = 1ll * (n - 1) * (a - b) + a;
                if (n == 1) {
                    cur_min = 1;
                    cur_max = a;
                }

                bool ok = false;
                i64 nxt_min = max(h_min, cur_min);
                i64 nxt_max = min(h_max, cur_max);
                if (nxt_max - nxt_min + 1 > 0) {
                    ok = true;
                    h_min = nxt_min;
                    h_max = nxt_max;
                }
                cout << (ok ? 1 : 0) << ' ';
            } else {
                i64 a, b;
                cin >> a >> b;
                
                i64 mn_need = f(h_min, a, b);
                i64 mx_need = f(h_max, a, b);
                // cout << mn_need << ' ' << mx_need << endl;
                if (mn_need == mx_need) {
                    cout << mn_need << ' ';
                } else {
                    cout << -1 << ' ';
                }
            }
        }
        cout << endl;
    }
    return 0;
}
