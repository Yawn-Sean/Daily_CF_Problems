#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    int n, L;
    cin >> n >> L;

    vector<int> c(n);
    for (auto& x : c) {
        cin >> x;
    }

    map<int, i64> costs;
    int mi = INT_MAX;
    for (int i = c.size() - 1; i >= 0; i--) {
        if (c[i] >= mi) continue;
        costs.emplace(i, c[i]);
        mi = c[i];
    }
    
    auto it = costs.begin();
    int pre_i = it->first;
    i64 pre_cst = it->second;
    for (it++; it != costs.end(); it++) {
        auto& [cur_i, cur_cst] = *it;
        cur_cst = min(cur_cst, pre_cst * (1 << (cur_i - pre_i)));
        pre_i = cur_i, pre_cst = cur_cst;
    }

    i64 ans = LONG_LONG_MAX;
    i64 rest = L;
    i64 tot_cst = 0LL;
    for (auto it = costs.rbegin(); rest > 0LL && it != costs.rend(); it++) {
        auto [i, cst] = *it;
        i64 m = 1 << i;
        int cnt = (rest + m - 1) / m;
        ans = min(ans, tot_cst + cst * cnt);
        tot_cst += rest / m * cst;
        rest -= rest / m * m;
    }
    
    cout << ans << "\n";

    return 0;
}
