#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5+10;

void solve() {
    int n, m, s = 0;
    cin >> n >> m;
    unordered_set<int> ust;
    vector<int> vec(n+1);
    vector<int> target(mx);
    vector<int> cur(mx);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
    for (int j = 1; j <= m; ++j) {
        cin >> target[j];
        if (target[j]) {
            ust.insert(j);
            s += target[j];
        }
    }
    int l = 1, ans = INT_MAX;
    for (int r = 1; r <= n; ++r) {
        int c = vec[r];
        cur[c]++;
        if (cur[c] == target[c]) {
            ust.erase(c);
        }
        if (ust.empty()) {
            while (l <= r && cur[vec[l]] > target[vec[l]]) {
                cur[vec[l]]--;
                l++;
            }
            ans = min(ans, r-l+1-s);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}

int main() {
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