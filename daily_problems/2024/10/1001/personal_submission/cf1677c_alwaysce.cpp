#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> perm1(n), perm2(n);
		for (auto& v: perm1) { cin >> v; v--; }
		for (auto& v: perm1) { cin >> perm2[v]; perm2[v]--; }
		// for (auto& v: perm2) { cout << perm2[v] << ' ' << perm2[perm2[v]] << '\n'; }
		// 对于perm2[i] = x的元素 perm2[i] - perm1[i] => perm2[i] - perm2[p[i]]
		// p[i]存储在了perm2中
		vector<int> seen(n);
		i64 half = 0;
		for (int i = 0; i < n; i++) {
			if (!seen[i]) {
				int cnt = 0;
				while (!seen[i]) {
					seen[i] = 1;
					i = perm2[i];
					cnt++;
				}
				// i -> p[i] 因为是排列构成了一个环
				half += cnt / 2;
			}
		}
		
		cout << half * 2ll * (n - half) << '\n';
	}
	return 0;
}
