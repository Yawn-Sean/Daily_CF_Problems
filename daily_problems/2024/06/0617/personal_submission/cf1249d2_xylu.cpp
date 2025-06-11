#include <bits/stdc++.h>
using namespace std;

void solveD2() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> segs(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i][0] >> segs[i][1];
        segs[i][2] = i;
    }
    sort(segs.begin(), segs.end(), [](const auto &a, const auto &b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    vector<int> ans;
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.begin()->first < segs[i][0]) {
            st.erase(st.begin());
        }

        st.insert({segs[i][1], segs[i][2]});
        while (st.size() > k) {
            auto it = prev(st.end());
            ans.push_back(it->second + 1);
            st.erase(it);
        }
    }
    cout << ans.size() << '\n';
    for (auto &a : ans) {
        cout << a << ' ';
    }
}

int main() {
    solveD2();
    return 0;
}
