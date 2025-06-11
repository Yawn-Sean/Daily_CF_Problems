#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	while (t--) {
		int n, k;
		std::cin >> n >> k;
		
		std::vector<int> a(n), b(k), pos(n + 1);
		std::vector<int> pre(n), nxt(n), used(n + 1);

		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			pos[a[i]] = i;
		}
		for (int i = 0; i < k; i++) {
			std::cin >> b[i];
			used[b[i]] = 1;
		}
		
		std::iota(pre.begin(), pre.end(), -1);
		std::iota(nxt.begin(), nxt.end(), 1);
		
		i64 ans = 1;
		auto f = [&](int x){
			int pre_idx = pre[x];
			int nxt_idx = nxt[x];
			if (pre_idx != -1)
				pre[x] = pre[pre_idx];
			if (nxt_idx != n)
				nxt[x] = nxt[nxt_idx];
		};
		
		for (int i = 0; i < k; i++) {
			int l = pre[pos[b[i]]], r = nxt[pos[b[i]]];
			i64 cnt = 0;
			if (l != -1 and !used[a[l]]) { ++cnt; }
			if (r != n and !used[a[r]]) { ++cnt; }
			ans = (ans * cnt) % mod;
			f(pos[b[i]]);
			used[b[i]] = 0;
		}
		
		std::cout << ans << '\n';
	}
	return 0;
}
