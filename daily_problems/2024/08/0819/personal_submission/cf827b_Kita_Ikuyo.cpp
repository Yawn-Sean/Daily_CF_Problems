#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL
#include "C:\Program Files\DEBUG\debug.h"
#else
#define debug(...) 114514
#define ps 114514
#endif

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    cout << (n - 1) / k * 2 + min(2ll, (n - 1) % k) << endl;
    for (int i = 1; i <= n - 1; i++) {
        if (i <= k) {
            cout << i << ' ' << n << endl;
        } else {
            cout << i << ' ' << i - k << endl;
        }
    }
    return 0;
}
