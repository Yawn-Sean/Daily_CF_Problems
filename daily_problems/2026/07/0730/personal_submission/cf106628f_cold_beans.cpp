#include <bits/stdc++.h>
using namespace std;
#define int long long

void run_case() {
    int n, k; cin >> n >> k;
    vector<int> nums(n+1); for (int i = 1; i <= n; i++) cin >> nums[i];

    vector<vector<int>> order(n+1); order[1].push_back(0);
    vector<int> ans;

    for (int i = 2; i <= n; i++) {
        priority_queue<pair<int, int>> pq;
        vector<int> pts(n+1);
        for (int j = 1; j < i; j++) {
            pq.push({order[j][0] + gcd(nums[i], nums[j]), j});
        }
        while (!pq.empty() && order[i].size() <= k) {
            auto [val, idx] = pq.top();
            order[i].push_back(val);
            pts[idx]++;
            pq.pop();
            if (pts[idx] < order[idx].size()) {
                pq.push({order[idx][pts[idx]] + gcd(nums[i], nums[idx]), idx});
            }
        }
        if (order[i].size() < k) order[i].push_back(0);
        for (auto item: order[i]) ans.push_back(item);
    }

    sort(ans.begin(), ans.end(), greater<int>());

    if (ans.size() < k) {
        cout << 0;
    }
    else {
        cout << ans[k-1];
    }

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run_case();
        cout << '\n';
    }
    return 0;
}