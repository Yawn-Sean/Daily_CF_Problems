#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll solution(int n, const vector<int>& nums, const vector<vector<int>>& conflictingPairs) {
    vector<int> p(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        p[nums[i]] = i;
    }

    vector<pair<int, int>> conflict;
    for (const auto& pair : conflictingPairs) {
        int u = pair[0], v = pair[1];
        int pos_u = p[u], pos_v = p[v];
        if (pos_u > pos_v) swap(pos_u, pos_v);
        conflict.push_back({pos_u, pos_v});
    }

    sort(conflict.begin(), conflict.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    ll ans = 0;
    int left = 0;
    int mx = -1;
    int total_conflicts = conflict.size();

    for (int right = 0; right < n; ++right) {
        while (left < total_conflicts && conflict[left].second <= right) {
            mx = max(mx, conflict[left].first);
            left++;
        }
        ans += right - mx;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<vector<int>> conflicts(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> conflicts[i][0] >> conflicts[i][1];
    }

    cout << solution(n, nums, conflicts) << endl;

    return 0;
}