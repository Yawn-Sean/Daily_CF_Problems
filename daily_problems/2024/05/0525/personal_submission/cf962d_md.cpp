// 0525
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<i64> nums(n);
    copy_n(istream_iterator<i64>(cin), n, begin(nums));

    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
    for (int i = 0; i < n; ++i) {
        pq.emplace(nums[i], i);
    }

    vector<int> indices;
    while (size(pq) >= 2) {
        auto[ai, i] = pq.top();
        pq.pop();
        auto[aj, j] = pq.top();
        pq.pop();

        if (ai == aj) {
            nums[j] = aj * 2;
            pq.emplace(aj * 2, j);
        } else {
            pq.emplace(aj, j);
            indices.emplace_back(i);
        }
    }

    if (!empty(pq)) {
        indices.emplace_back(pq.top().second);
    }

    sort(begin(indices), end(indices));

    cout << size(indices) << endl;
    for (auto i : indices) {
        cout << nums[i] << ' ';
    }
    cout << endl;

    return 0;
}