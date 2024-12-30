#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; int m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&] (int k) {
        int prev = 0;
        for (auto elm : a) {
            // 1. add k can cover
            if (elm <= prev && elm + k >= prev) {
                continue;
            }
            if (elm + k >= m && elm + k - m >= prev) {
                continue;
            }
            // 2, bump prev
            if (elm > prev) {
                prev = elm;
            } else {
                return false;
            }
        }
        return true;
    };

    int l = 0, r = m;
    while (r - l > 5) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    for (int i = l; i <= r; i++) {
        if (check(i)) {
            cout << i << "\n";
            return;
        }
    }

}

int main(void) {
    
    ios::sync_with_stdio(false);

    int T{1};
    // cin >> T;
    while (T--) {
        solve();
    }

}