#include <bits/stdc++.h>
 
using namespace std;
constexpr int N = 2e5;
int s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        for (int i = 0; i < m; i++) {
            cin >> s[i];
        }
        sort(begin(s), begin(s) + m);
        auto check = [&] (int k) -> bool {
            int mx = 0;
            for (int i = k - 1; i >= 0; i--) {
                mx = max(mx, s[i] + (k - i));
            }
            int t = a < b ? b - 1 : n - b;
            return mx <= t;
        };
        int lo = 0, hi = min(abs(a - b) - 1, m);
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (check(mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << hi << "\n";
    }
    return 0;
}

