#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n, -1);
    vector<int> ele(n);
    set<int> st;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        ele[i] = cur;
        // find the place that is just smaller than cur
        auto it = st.lower_bound(cur);
        if (st.empty() || it == st.begin()) {
            st.insert(cur);
            mp[cur] = st.size();
            vc[i] = st.size();
        } else {
            --it;
            mp[cur] = mp[*it];
            st.erase(it);
            st.insert(cur);
            vc[i] = mp[cur];
        }
    }
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[vc[i] - 1].push_back(ele[i]);
    }
    for (auto& v : ans) {
        if (v.empty()) return;
        for (auto& e : v) {
            cout << e << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
