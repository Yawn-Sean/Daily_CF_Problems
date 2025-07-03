#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<i64> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<i64> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    i64 ans = -1;
    i64 left = 0, right = 2e10 + 1;
    while (left < right) {
        i64 mid = (left + right) / 2;

        int p_pt = 0;
        for (int h_pt = 0; h_pt < n; h_pt++) {
            i64 max_r;
            if (h[h_pt] < p[p_pt]) {
                max_r = h[h_pt] + mid;
            } else {
                i64 diff = h[h_pt] - p[p_pt];
                if (mid < diff) { continue; }
                i64 r1 = (mid - diff) / 2;
                i64 r2 = (mid - 2ll * diff);
                max_r = h[h_pt] + max(r1, r2);
            }
            while (p_pt < m && p[p_pt] <= max_r) {
                p_pt++;
            }
        }

        if (p_pt < m) {
            left = mid + 1;
        } else {
            ans = mid;
            right = mid;
        }
    }

    cout << ans << endl;
    return 0;
}
