#include <bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n, m, p;
	std::cin >> n >> m >> p;
	std::vector<u64> a(n), b(m);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::vector<int> ans;
	std::map<u64, u64> mpx, mpa;
	std::mt19937_64 rnd((unsigned)time(0));

	for (int i = 0; i < m; i++) {
		if (mpx.find(b[i]) == mpx.end()) {
			mpx[b[i]] = rnd();
			mpa[b[i]] = rnd();
		}
	}
	u64 wx = 0, wa = 0;
	for (int i = 0; i < m; i++) {
		wx ^= mpx[b[i]];
		wa += mpa[b[i]];
	}

	for (int i = 0; i < n; i++) {
		if (mpx.find(a[i]) == mpx.end()) {
			mpx[a[i]] = rnd();
			mpa[a[i]] = rnd();
		}
	}
	for (int r = 0; r < p; r++) {
		std::vector<u64> prex, prea;
		prex.push_back(0);
		prea.push_back(0);
		u64 accx = 0, acca = 0;
		for (int j = r; j < n; j += p) {
			accx ^= mpx[a[j]];
			acca += mpa[a[j]];
			prex.push_back(accx);
			prea.push_back(acca);
		}
		for (int j = m; j < (int)prex.size(); j++) {
			u64 segx = prex[j] ^ prex[j - m];
			u64 sega = prea[j] - prea[j - m];
			if (segx == wx && sega == wa) {
				ans.push_back(r + (j - m) * p + 1);
			}
		}
	}

	std::sort(ans.begin(), ans.end());
	std::cout << ans.size() << endl;
	for (auto x : ans) std::cout << x << " ";
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
