#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll BOUND = 1e12;

ll safe_lcm(ll a, ll b) {
    ll g = std::gcd(a, b);
    a /= g;

    if (a > BOUND / b) return BOUND;
    
    ll res = a * b;
    return min(res, BOUND);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, l, r, k;
    cin >> n >> l >> r >> k;

    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (*min_element(nums.begin(), nums.end()) <= k) {
        cout << -1 << "\n";
        return 0;
    }

    ll ans = 1;

    for (ll x : nums) {
        ans = safe_lcm(ans, x);
    }
    ll candidate = (r - k) / ans * ans + k;

    if (candidate >= l && candidate <= r)
        cout << candidate << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
