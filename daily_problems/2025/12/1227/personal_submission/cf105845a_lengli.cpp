#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 1000000007;

ll modpow(ll a, ll e) {
    ll r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

ll modinv(ll a) {
    return modpow(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && nums[j] == nums[i]) j++;
        cnt[i] = j - i;
        i = j;
    }

    ll last_k = 0, last_b = 0;
    ll k = 0, b = 0;
    ll cur = -1;
    ll resid = n;

    for (int i = n - 1; i >= 0; i--) {
        if (cnt[i] == 0) continue;

        if (cur == -1) {
            last_k = 1;
            last_b = 0;
        } else {
            ll rev_resid = modinv(resid);

            ll vk = n * rev_resid % MOD;
            ll rev_vk_1 = modinv((vk - 1 + MOD) % MOD);
            ll pw_vk = modpow(vk, cur - nums[i]);

            ll vb = (MOD - k) * rev_resid % MOD;
            ll fix = (MOD - vb) * rev_vk_1 % MOD;
            last_k = ((last_k - fix + MOD) % MOD * pw_vk + fix) % MOD;

            vb = (MOD - (n + b) % MOD) * rev_resid % MOD;
            fix = (MOD - vb) * rev_vk_1 % MOD;
            last_b = ((last_b - fix + MOD) % MOD * pw_vk + fix) % MOD;
        }

        k = (k + last_k * cnt[i]) % MOD;
        b = (b + last_b * cnt[i]) % MOD;
        cur = nums[i];
        resid -= cnt[i];
    }

    ll ans = (MOD - last_b) * modinv(last_k) % MOD;
    cout << ans << '\n';

    return 0;
}
