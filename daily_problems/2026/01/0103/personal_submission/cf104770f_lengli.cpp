#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    vector<int> cnt(n, 0);

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
        cnt[idx]++;
    }

    vector<vector<long long>> vals(n);
    int c = 0;

    for (int i = 0; i < n; i++) {
        if (cnt[i]) {
            vals[i].push_back(nums[i]);
            cnt[i]--;
            c++;
        }
    }

    if (2 * c - 1 != n) {
        cout << -1 << '\n';
        return 0;
    }

    int cur = (n + 1) / 2;

    while (cur > 1) {
        vector<int> p1, p2;

        for (int i = 0; i < n; i++) {
            if (cnt[i]) p1.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0 && !vals[i].empty())
                p2.push_back(i);
        }

        if ((int)p1.size() != (int)p2.size()) {
            cout << -1 << '\n';
            return 0;
        }

        for (size_t i = 0; i < p1.size(); i++) {
            int x = p1[i];
            int y = p2[i];
            if (x > y) {
                cout << -1 << '\n';
                return 0;
            }
            vals[x].insert(vals[x].end(), vals[y].begin(), vals[y].end());
            vals[y].clear();
            cnt[x]--;
        }

        cur = (cur + 1) / 2;
    }

    for (int i = 0; i < (int)vals[0].size(); i++) {
        if (i) cout << ' ';
        cout << vals[0][i];
    }
    cout << '\n';

    return 0;
}
