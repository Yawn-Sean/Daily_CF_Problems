#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    string u, v;
    cin >> u >> v;
    vector<int> cnt(3);
    for (const auto& x : u) {
        cnt[x - 'A']++;
    }
    for (const auto& x : v) {
        cnt[x - 'A']--;
    }

    for (int i = 0; i < 3; i++) {
        if (cnt[i] & 1) {
            cout << "NO\n";
            return;
        }
    }

    auto get = [&](string& s) -> vector<int> {
        vector<int> ans;
        for (const auto& v : s) {
            if (v == 'B') {
                continue;
            }
            if (!ans.empty() && ans.back() == v) {
                ans.pop_back();
            } else {
                ans.push_back(v);
            }
        }
        return ans;
    };

    if (get(u) == get(v)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}