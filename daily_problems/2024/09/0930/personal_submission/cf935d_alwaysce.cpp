#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1e9 + 7;

i64 pow(i64 a, i64 b) {
	a %= mod;
    i64 res = 1;
    for (; b; b /= 2, a = a * a % mod) {
        if (b % 2) {
            res = res * a % mod;
        }
    }
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n, m;
	cin >> n >> m;
	
	vector<int> s1(n), s2(n);
	for (auto& x: s1) { cin >> x; }
	for (auto& x: s2) { cin >> x; }
	
	i64 ans = 0, prob = 1;
	i64 inv2 = pow(2ll, mod - 2);
	i64 invm = pow(m, mod - 2);
	
	for (int i = 0; i < n; i++) {
		if (s1[i] != 0) {
			if (s2[i] != 0) {
				if (s1[i] > s2[i]) {
					ans = (ans + prob) % mod;
					break;
				} else if (s1[i] < s2[i]) {
					break;
				}
			} else {
				// s2[i] < s1[i]
				prob = 1ll * prob * invm % mod;
				ans = (ans + 1ll * prob * (s1[i] - 1) % mod) % mod;
			}
		} else {
			// s1[i] > s2[i]
			if (s2[i] != 0) {
				prob = 1ll * prob * invm % mod;
				ans = (ans + 1ll * prob * (m - s2[i]) % mod) % mod;
			} else {
				prob = 1ll * prob * invm % mod;
				ans = (ans + 1ll * prob * (m - 1) % mod * inv2 % mod) % mod;
			}
		}
	}
	cout << ans;
	
	return 0;
}
