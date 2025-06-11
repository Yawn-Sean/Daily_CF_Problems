#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n, K; scanf("%d%d", &n, &K);
    map<int, vector<pii>> mp;
    for (int i = 1; i <= n; i++) {
        int l, r; scanf("%d%d", &l, &r);
        mp[l].push_back({r, i});
    }

    vector<int> ans;
    set<pii> st;
    for (auto &entry : mp) {
        int pos = entry.first;
        while (!st.empty() && st.begin()->first < pos) st.erase(st.begin());
        auto &vec = entry.second;
        for (pii p : vec) st.insert(p);
        while (st.size() > K) {
            ans.push_back(prev(st.end())->second);
            st.erase(prev(st.end()));
        }
    }
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
