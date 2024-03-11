#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;

    int len = r - l + 1;
    int maxsum = (n + (n - len + 1)) * len / 2;
    int minsum = (1 + len) * len / 2;
    if (maxsum < s || minsum > s) {
        cout << -1 << endl;
        return;
    }

    vector<int> selected(n + 1);
    int sum = minsum;
    fill(begin(selected) + 1, begin(selected) + len + 1, 1);

    for (int start_idx = len; sum < s ; start_idx++) {
        int idx = start_idx;
        while (sum < s && start_idx - idx + 1 <= len) {
            selected[idx] = 0;
            selected[idx + 1] = 1;
            ++sum;
            --idx;
        }
    }

    vector<int> ret(n + 1);
    int selected_idx = l;
    vector<int> unselected;
    for (int i = 1; i <= n; ++i) {
        if (selected[i]) {
            ret[selected_idx++] = i;
        } else {
            unselected.push_back(i);
        }
    }
    
    int unselected_idx = size(unselected) - 1;
    for (int i = 0; i < n; ++i) {
        if (ret[i + 1] == 0) {
            cout << unselected[unselected_idx--] << " ";
        } else {
            cout << ret[i + 1] << " ";
        }
    }
    cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}