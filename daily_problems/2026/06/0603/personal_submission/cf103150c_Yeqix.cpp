#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    string s;
    cin >> s;

    set<char> st;
    for (const auto& v : s) {
        if (v == 'p' && !st.count('z')) {
            cout << "NO\n";
            return;
        }
        if (v == 'c' && (!st.count('e') || !st.count('z') || !st.count('p'))) {
            cout << "NO\n";
            return;
        }
        st.insert(v);
    }

    cout << "YES\n";
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