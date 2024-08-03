#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;

    vector<pair<int, int>> n2c(n);
    for (int i = 0; i < n; ++i) {
        cin >> n2c[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> n2c[i].second;
    }
    sort(n2c.begin(), n2c.end());

    multiset<int> cur_nums;
    int64_t cur_sum{};
    int64_t ans{};
    int cur_pos{-1};
    auto iter = n2c.begin();

    while (iter != n2c.end() || cur_nums.size()) {
        if (!cur_nums.size()) {
            cur_pos = iter->first;
        } 
        
        while (iter != n2c.end() && iter->first == cur_pos) {
            cur_nums.insert(iter->second);
            cur_sum += iter->second;
            iter++;
        }

        if (cur_nums.size()) {
            auto fv = *cur_nums.rbegin();
            cur_nums.erase(cur_nums.find(fv));
            cur_sum -= fv;
            ans += cur_sum;
            cur_pos++;
        }
    }

    cout << ans << "\n";
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