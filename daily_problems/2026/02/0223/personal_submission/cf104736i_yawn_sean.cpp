#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    string s;
    long long n;
    int mod = 1e9 + 7;

    cin >> s >> n;
    n %= mod;

    vector<int> cnt(26, 0);
    int ans = 0;

    for (auto &c: s) {
        int ch = c - 'a';
        for (int j = ch + 1; j < 26; j ++) {
            ans += cnt[j];
            ans %= mod;
        }
        cnt[ch] ++;
    }

    ans = n * ans % mod;

    for (int i = 0; i < 26; i ++) {
        for (int j = 0; j < i; j ++) {
            ans += n * (n - 1) / 2 % mod * cnt[i] % mod * cnt[j] % mod;
            ans %= mod;
        }
    }

    cout << ans;

	return 0;
}