//20260115_cf104375d_Travor007.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;
const int MX = 3e5 + 12;
const char nl = '\n';

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    sort(nums.begin(), nums.end());
    
    while (q--) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int v;
            cin >> v;
            
            if (v > nums.back()) {
                nums.emplace_back(v);
            } else {
                int pos = upper_bound(nums.begin(), nums.end(), v) - nums.begin();
                if (pos && nums[pos - 1] == v) continue;
                else nums[pos] = v;
            }
        } else {
            int l, r;
            cin >> l >> r;
            cout << upper_bound(nums.begin(), nums.end(), r) - lower_bound(nums.begin(), nums.end(), l) << '\n';
        }
    }
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
