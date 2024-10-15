#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;

i64 comb(int x, int y) {
	if (y > x) { return 0ll; }
	i64 ans = 1ll;
	// x! / y! (x-y)!
	// x x-1 ... 
	for (int i = 0; i < y; i++) {
		ans = ans * (x - i) / (i + 1);
	}
	return ans;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, k;
	std::cin >> n >> k;
	
	auto get_d = [&](int k) {
		std::vector<i64> d(5, 0);
		
		for (int l = 1; l <= k; l++) {
			std::vector<int> perm(l);
			std::iota(perm.begin(), perm.end(), 1);
			
			do {
				bool ok = true;
				for (int i = 1; i <= l; i++) {
					if (perm[i - 1] == i) {
						ok = false;
						break;
					}
				}
				if (ok) {
					d[l]++;
				}
			} while (std::next_permutation(perm.begin(), perm.end()));
			
		}
		return d;
	};
	
	std::vector<i64> d = get_d(k);
	
	i64 res = 1ll;
	for (int i = 0; i <= k; i++) {
		res += d[i] * comb(n, i);
	}
	std::cout << res << '\n';
	return 0;
}
