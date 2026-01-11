#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    const long long mod = 998244353;

    long long ans = 1;
    long long cur = 0;

    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) {
            cur += 1;
        } else {
            ans = (ans * cur) % mod;
            cur -= 1;
        }
    }
    cur = 0;
    for (int i = n - 1; i >= n % 2; --i) {
        if (nums[i] != 0) {
            ans = (ans * cur) % mod;
            cur -= 1;
        } else {
            cur += 1;
        }
    }

    cout << ans % mod << '\n';
    return 0;
}
