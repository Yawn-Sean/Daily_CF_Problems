#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<long long, set<int>> g;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        g[x].insert(i);
    }
    for (auto& [x, indices] : g) {
        int k = indices.size();
        if (k > 1) {
            auto it_cur = indices.begin();
            while (it_cur != indices.end()) {
                auto it_nxt = it_cur;
                if (++it_nxt == indices.end()) break;
                g[x*2].insert(*it_nxt);
                indices.erase(it_cur);
                it_cur = indices.erase(it_nxt);
            }
        }
    }
    set<pair<int, long long>> st;
    for (auto& [x, indices] : g) {
        if (!indices.empty()) {
            st.insert({*indices.begin(), x});
        }
    }
    cout << st.size() << "\n";
    for (auto& [i, x] : st) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

