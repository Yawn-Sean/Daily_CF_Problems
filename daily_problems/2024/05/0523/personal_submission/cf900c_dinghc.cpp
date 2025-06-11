#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p) {
        cin >> x;
        x--;
    }
    vector<int> cnt(n, 0);
    set<int> st;
    for (auto& x : p) {
        st.insert(x);
        if (*st.rbegin() == x) {
            cnt[x]--;
        } else {
            auto it = st.end();
            if (--it != st.begin()) {
                if (*--it == x) cnt[*st.rbegin()]++;
            }
        }
    }
    pair<int, int> ans{-2, 1};
    for (int i = 0; i < n; i++) {
        ans = max(ans, pair<int, int>{cnt[i], -i});
    }
    cout << -ans.second + 1 << "\n";
    return 0;
}

