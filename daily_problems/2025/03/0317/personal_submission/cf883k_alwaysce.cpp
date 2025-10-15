#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> s(n), g(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> g[i];
    }

    vector<int> lo(n), hi(n);
    lo[0] = s[0];
    hi[0] = s[0] + g[0];

    for (int i = 1; i < n; i++) {
        int cur_lo = s[i];
        int cur_hi = s[i] + g[i];

        lo[i] = max(lo[i - 1] - 1, cur_lo);
        hi[i] = min(hi[i - 1] + 1, cur_hi);
        if (lo[i] > hi[i]) {
            cout << -1;
            return 0;
        }
    }

    vector<int> ansL;
    i64 mx = hi[n - 1];
    i64 ans = mx - s[n - 1];
    ansL.push_back(mx);
    for (int i = n - 2; i >= 0; i--) {
        i64 new_mx = mx + 1;
        if (new_mx <= hi[i]) {
            ansL.push_back(new_mx);
            mx = new_mx;
            ans += new_mx - s[i];
            continue;
        }
        new_mx = mx;
        if (new_mx <= hi[i]) {
            ansL.push_back(new_mx);
            mx = new_mx;
            ans += new_mx - s[i];
            continue;
        }
        new_mx = mx - 1;
        if (new_mx <= hi[i]) {
            ansL.push_back(new_mx);
            mx = new_mx;
            ans += new_mx - s[i];
            continue;
        }
        
    }
    cout << ans << '\n';
    for (int i = ansL.size() - 1; i >= 0; i--) {
        cout << ansL[i] << ' ';
    }
    return 0;
}
