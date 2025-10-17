#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    set<int> st;
    st.insert(0);
    auto dfs = [&](auto&& dfs, int x, int y, ll cur) -> void {
        if (cur > n) {
            return;
        }
        st.insert(cur);
        dfs(dfs, x, y, cur * 10 + x);
        dfs(dfs, x, y, cur * 10 + y);
    };
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            dfs(dfs, i, j, i);
        }
    }
    for (auto x : st) {
        if (st.count(n - x)) {
            ans++;
        }
    }
    cout <<( ans + 1) / 2 << '\n';
    return 0;
}