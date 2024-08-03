#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;

    vector<pair<int,int>> l_nums;
    while (n--) {
        int v; cin >> v;
        if (l_nums.empty() || l_nums.back().first != v) {
            l_nums.emplace_back(v, 1);
        } else {
            l_nums.back().second++;
        }
    }

    vector<int> ans(4);
    for (auto elm: l_nums) {
        if (elm.first == 1) {
            ans[0] += elm.second;
            ans[2] += elm.second;
        } else {
            ans[1] += elm.second;
            ans[3] += elm.second;
        }
        for (int i = 1; i < 4; i++) {
            ans[i] = max(ans[i], ans[i - 1]);
        }
    }
    cout << ans[3] << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}