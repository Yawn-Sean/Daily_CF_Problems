#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    copy_n(istream_iterator<int>(cin), n, begin(nums));

    auto ones = count(begin(nums), end(nums), 1);
    
    if (ones == n) {
        cout << 0;
        return 0;
    }

    int min_ops = n + 1;
    for (int i = 0; i < n; ++i) {
        int val = nums[i];
        for (int j = i + 1; j < n; ++j) {
            val = __gcd(val, nums[j]);
            if (val == 1) {
                min_ops = min(min_ops, j - i);
                break;
            }
        }
    }

    if (min_ops == n + 1) {
        cout << -1;
    } else {
        cout << n - 1 - ones + min_ops;
    }

    return 0;
}