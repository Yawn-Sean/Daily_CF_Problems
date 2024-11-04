#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ans;
    while (n--) {
        int v; cin >> v;
        auto it = ranges::lower_bound(ans, v, ranges::greater(), [](const vector<int> &vec) { return vec.back(); });
        if (it == ans.end()) ans.push_back(vector<int>{v});
        else it->push_back(v);
    }
    for (auto &vec: ans) {
        for (auto &v: vec) print("{} ", v);
        println();
    }
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
