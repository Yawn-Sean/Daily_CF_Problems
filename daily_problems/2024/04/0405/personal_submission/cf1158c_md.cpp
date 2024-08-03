#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nxt(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nxt[i];
        if (nxt[i] == -1) {
            nxt[i] = i + 1;
        } else {
            --nxt[i];
        }
    }

    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        pos[nxt[i]].push_back(i);
    }

    vector<int> ret(n);
    int cur = 1;
    for (auto p : pos) {
        for (auto id : p | views::reverse) {
            ret[id] = cur++;
        }
    }

    stack<int> st;
    st.push(n);
    for (int i = n - 1; i >= 0; --i) {
        while (st.top() != n && ret[i] > ret[st.top()]) {
            st.pop();
        }

        if (nxt[i] != st.top()) {
            std::cout << "-1\n";
            return;
        }
        st.push(i);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ret[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}