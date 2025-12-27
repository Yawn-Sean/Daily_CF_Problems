#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<ll> outs;
    outs.reserve(t);

    while (t--) {
        int n;
        cin >> n;

        vector<ll> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<ll> tmp;
        tmp.reserve(2 * n + 1);
        tmp.push_back(-1);
        for (ll x : nums) {
            tmp.push_back(x);
            tmp.push_back(-1);
        }

        int m = 2 * n + 1;
        vector<int> wing(m, 0);

        int idx = 0;
        for (int i = 0; i < m; i++) {
            if (idx + wing[idx] >= i) {
                int mirror = 2 * idx - i;
                if (mirror >= 0 && mirror < m) {
                    wing[i] = min(wing[mirror], idx + wing[idx] - i);
                }
            }

            while (i > wing[i] &&
                   i + wing[i] < m - 1 &&
                   tmp[i - wing[i] - 1] == tmp[i + wing[i] + 1]) {
                wing[i]++;
            }

            if (i + wing[i] > idx + wing[idx]) {
                idx = i;
            }
        }

        vector<ll> diff_k(n + 1, 0);
        vector<ll> diff_b(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int l = (i - wing[i]) / 2;
            int r = (i + wing[i]) / 2;

            int mid = (l + r + 1) / 2;

            diff_k[l] += 1;
            diff_k[mid] -= 1;
            diff_b[l] -= (l - 1);
            diff_b[mid] += (l - 1);

            diff_k[mid] -= 1;
            diff_k[r] += 1;
            diff_b[mid] += r;
            diff_b[r] -= r;
        }

        for (int i = 0; i < n; i++) {
            diff_k[i] = (diff_k[i] % MOD + MOD) % MOD;
            diff_b[i] = (diff_b[i] % MOD + MOD) % MOD;
            diff_k[i + 1] = (diff_k[i + 1] + diff_k[i]) % MOD;
            diff_b[i + 1] = (diff_b[i + 1] + diff_b[i]) % MOD;
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll val = (diff_k[i] * i + diff_b[i]) % MOD;
            ans = (ans + val * nums[i]) % MOD;
        }

        outs.push_back(ans);
    }

    for (ll x : outs) {
        cout << x << '\n';
    }

    return 0;
}
