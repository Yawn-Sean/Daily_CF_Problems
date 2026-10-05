#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ans;
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
            st.insert(i);
        }
    }

    auto dfs = [&](this auto&& dfs, int l, int r) -> int {
        if (l > r) {
            return 1;
        }

        auto it = st.lower_bound(l);
        if (it != st.end() && (*it) <= r) {
            int i = (*it);
            ans.push_back(i + 1);
            st.erase(it);
            if (i > l) {
                if (s[i - 1] == 'D') {
                    st.erase(i - 1);
                } else {
                    st.insert(i - 1);
                }
                s[i - 1] = (s[i - 1] == 'D' ? 'B' : 'D');
            }
            if (i < r) {
                if (s[i + 1] == 'D') {
                    st.erase(i + 1);
                } else {
                    st.insert(i + 1);
                }
                s[i + 1] = (s[i + 1] == 'D' ? 'B' : 'D');
            }
            return dfs(l, i - 1) && dfs(i + 1, r);
        }

        return 0;
    };

    if (dfs(0, n - 1)) {
        cout << "Y\n";
        for (const auto& v : ans) {
            cout << v << ' ';
        }
        cout << "\n";
    } else {
        cout << "N\n";
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