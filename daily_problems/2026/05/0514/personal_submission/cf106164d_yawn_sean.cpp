#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

const int mod = 998244353, rev2 = (mod + 1) / 2;

int op(int x, int y) {return min(x, y);}

int e() {return 1'000'000;}

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

void fwt_xor(vector<int>& nums, int bit, int type) {
	for (int i = 0; i < bit; i++) {
		int mask = 1 << i;
		for (int j = 0; j < (1 << bit); j += 2 * mask) {
			for (int k = 0; k < mask; k ++) {
				int x = nums[j + k], y = nums[j + mask + k];
				nums[j + k] = (x + y) % mod;
				nums[j + mask + k] = (x - y + mod) % mod;
				if (type == -1) {
					nums[j + k] = 1ll * nums[j + k] * rev2 % mod;
					nums[j + mask + k] = 1ll * nums[j + mask + k] * rev2 % mod;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, r;
	cin >> n >> k >> r;

	vector<int> sg(n + 1, -1);
	atcoder::segtree<int, op, e> seg(sg);

	sg[0] = 0; seg.set(0, 0);

	for (int i = 1; i <= n; i ++) {
		int v;
		cin >> v;
		sg[i] = seg.max_right(0, [&] (int x) {return x >= i - v;});
		seg.set(sg[i], i);
	}

	int ans = 0;

	vector<int> cnt(1 << 19, 0);

	for (auto &x: sg) cnt[x] ++;

	fwt_xor(cnt, 19, 1);

	for (int i = 0; i < 1 << 19; i ++) cnt[i] = quickPow(cnt[i], r, mod);

	fwt_xor(cnt, 19, -1);

	ans += cnt[0];

	fill(cnt.begin(), cnt.end(), 0);

	for (int i = 0; i <= n; i ++) {
		if (i + k > n || sg[i] == sg[i + k]) {
			cnt[sg[i]] ++;
		}
	}

	fwt_xor(cnt, 19, 1);

	for (int i = 0; i < 1 << 19; i ++) cnt[i] = quickPow(cnt[i], r, mod);

	fwt_xor(cnt, 19, -1);

	ans -= cnt[0];

	cout << (ans + mod) % mod;

	return 0;
}