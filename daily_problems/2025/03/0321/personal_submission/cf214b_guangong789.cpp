#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, sum = 0, tmp;
    cin >> n;
    map<int, int, greater<int>> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        cnt[tmp]++;
        sum += tmp;
    }
    if (cnt[0] == 0) {
        cout << -1;
        return;
    }
    int m = sum % 3;
    if (m == 1) {
        if (cnt[1]) {
            cnt[1]--;
        } else if (cnt[4]) {
            cnt[4]--;
        } else if (cnt[7]) {
            cnt[7]--;
        } else {
            if (cnt[2] > 1) {
                cnt[2] -= 2;
            } else if (cnt[2] && cnt[5]) {
                cnt[2]--;
                cnt[5]--;
            } else if (cnt[5] > 1) {
                cnt[5] -= 2;
            } else if (cnt[2] && cnt[8]) {
                cnt[2]--;
                cnt[8]--;
            } else if (cnt[5] && cnt[8]) {
                cnt[5]--;
                cnt[8]--;
            } else {
                cout << -1;
                return;
            }
        }
    } else if (m == 2) {
        if (cnt[2]) {
            cnt[2]--;
        } else if (cnt[5]) {
            cnt[5]--;
        } else if (cnt[8]) {
            cnt[8]--;
        } else {
            if (cnt[1] > 1) {
                cnt[1] -= 2;
            } else if (cnt[1] && cnt[4]) {
                cnt[1]--;
                cnt[4]--;
            } else if (cnt[4] > 1) {
                cnt[4] -= 2;
            } else if (cnt[1] && cnt[7]) {
                cnt[1]--;
                cnt[7]--;
            } else if (cnt[4] && cnt[7]) {
                cnt[4]--;
                cnt[7]--;
            } else if (cnt[7] > 1) {
                cnt[7] -= 2;
            } else {
                cout << -1;
                return;
            }
        }
    }
    if (cnt.size() == 1 && cnt[0]) {
        cout << 0;
    } else {
        bool leadingzero = true;
        for (auto& [key, value] : cnt) {
            while (value--) {
                if (leadingzero && key == 0) continue;
                leadingzero = false;
                cout << key;
            }
        }
        if (leadingzero) cout << 0;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}