#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (n == 2) {
        cout << 1 << endl;
        return;
    }

    vector<int> ids(n);
    iota(begin(ids), end(ids), 0);
    sort(begin(ids), end(ids), [&](auto&& lhs, auto&& rhs) {
        return nums[lhs] < nums[rhs];
    });
        
    auto checkMatches = [&](int firstIdx, int secondIdx) -> vector<int> {
        int diff = nums[ids[secondIdx]] - nums[ids[firstIdx]];
        int expected = nums[ids[secondIdx]];
        vector<int> mismatchIndices;
        for (int i = secondIdx; i < n; ++i) {
            if (expected != nums[ids[i]]) {
                mismatchIndices.push_back(ids[i]);
            } else {
                expected += diff;
            }
        }
        return mismatchIndices;
    };
    
    for (auto[first, second, expected] : initializer_list<tuple<int, int, int>>{{0, 1, 0}, {1, 2, 0}, {0, 2, 1}}) {
        auto mismatchIndices = checkMatches(first, second);
        if (size(mismatchIndices) == 0) {
            cout << ids[expected] + 1 << endl;
            return;
        }

        if (size(mismatchIndices) == 1 && first == 0 && second == 1) {
            cout << mismatchIndices[0] + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}