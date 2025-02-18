#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int64 mod = 1'000'000'007;

int fast_pow(int64 a, int64 b) {
    int64 ans = 1LL;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i - 1] - '0');
    }
    for (int i = 0, l, r; i < q; i++) {
        cin >> l >> r;
        int m = pref[r] - pref[l - 1];
        int k = r - l + 1 - m;
        cout << (fast_pow(2, m) + mod - 1) % mod * fast_pow(2, k) % mod << "\n";
    }
    return 0;
}

