#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL a, b, n;
LL l, t, m;

bool check(int r) {
    return ((a + (l - 1ll) * b) + (a + (r - 1ll) * b)) * (r - l + 1ll) / 2ll <= m * t && (a + (r - 1ll) * b) <= t;
}

int main() {
    cin >> a >> b >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> l >> t >> m;
        // cout << check(4) << endl;
        if (a + (l - 1ll) * b > t) cout << -1 << endl;
        else {
            LL sl = l, sr = 10000000000;
            while (sl < sr) {
                int mid = sl + sr + 1 >> 1;
                if (check(mid)) sl = mid;
                else sr = mid - 1;
            }
            cout << sl << endl;
        }
    }
    return 0;
}
