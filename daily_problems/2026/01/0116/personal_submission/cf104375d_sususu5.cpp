#include <algorithm>
#include <bit>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <stack>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MOD = 1e9 + 7;

ll query(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    ll x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

void report(ll m) {
    cout << "! " << m << '\n';
    cout.flush();
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    ranges::sort(nums);
    while (q--) {
        int no;
        cin >> no;
        if (no == 1) {
            int k;
            cin >> k;
            auto it = ranges::lower_bound(nums, k);
            if (it - nums.begin() == k) continue;
            if (k > nums[nums.size() - 1]) {
                nums.push_back(k);
                continue;
            }
            it = ranges::lower_bound(nums, k);
            *it = k;
        }
        if (no == 2) {
            int a, b;
            cin >> a >> b;
            auto it1 = ranges::lower_bound(nums, a);
            auto it2 = ranges::upper_bound(nums, b);
            cout << it2 - it1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}