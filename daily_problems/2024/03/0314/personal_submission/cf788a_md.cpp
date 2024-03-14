#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;
    vector<int> values(n);
    copy_n(istream_iterator<int>(cin), n, begin(values));

    array<vector<int>, 2> partialSum;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            partialSum[i].push_back(abs(values[j] - values[j + 1]) * (j % 2 == i ? 1 : -1));
        }
    }

    auto calc = [](const vector<int>& nums, int oddOrEven) -> long long {
        long long min_prefix = 0;
        long long sum = 0;
        long long ret = 0;
        for (int i = 0; i < size(nums); ++i) {
            sum += nums[i];
            if (i % 2 == oddOrEven) {
                ret = max(ret, sum - min_prefix);
            } else {
                min_prefix = min(min_prefix, sum);
            }
        }
        return ret;
    };

    cout << max(calc(partialSum[0], 0), calc(partialSum[1], 1)); 
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