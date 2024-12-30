#include <bits/stdc++.h>

using namespace std;
using li = long long;
constexpr int MXN = 200'000;
int a[MXN + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(begin(a), begin(a) + n);
        int ans = 0;
        vector<int> pref(k + 1, 0);
        for (int i = 0; i < k; i++) {
            int q = p - pref[i];
            if (q <= 0) {
                if (q == 0) ans = max(ans, i);
                break;
            }
            int t = i;
            int j = 1;
            while (k * j + i - 1 < n && q - a[k * j + i - 1] >= 0) {
                q -= a[k * j + i - 1];
                t += k;
                j += 1;
            }
            ans = max(ans, t);
            pref[i + 1] = pref[i] + a[i];
        }
        cout << ans << "\n";
    }
    return 0;
}

