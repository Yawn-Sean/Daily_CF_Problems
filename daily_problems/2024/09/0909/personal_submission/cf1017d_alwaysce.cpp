#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, q;
	cin >> n >> m >> q;

	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	
	map<int, int> cnt;	
	
	auto getval = [&](string& s) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = ans * 2 + (s[i] - '0');
		}
		return ans;
	};
	
	auto op = [&](int x, int y) {
		// 把x变成y的bitmask是什么?
		int bitmask = 0;
		for (int i = 0; i < n; i++) {
			if (((x >> i) & 1) == ((y >> i) & 1)) {
				bitmask |= (1 << i);
			}
		}
		return bitmask;
	};
	
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		cnt[getval(tmp)]++;
	}

	int MX = 1 << n;
	
	vector<int> f(MX);
	for (int i = 1; i < MX; i++) {
		int lb = i & -i;
		// lb是第几位(从高到低) => 32 - rk = 从低到高的顺序
		f[i] = f[i - lb] + w[n - (32 - __builtin_clz(lb))];
	}
 	
	vector<vector<int>> ans(101, vector<int>(MX));
	for (int x = 0; x < MX; x++) {
		for (int y = 0; y < MX; y++) {
			int cost = f[op(x, y)];
			if (cost <= 100) {
				ans[cost][x] += cnt[y];
			}
		}
		
		for (int y = 1; y <= 100; y++) {
			ans[y][x] += ans[y - 1][x];
		}
	}
	
	for (int i = 0; i < q; i++) {
		string t;
		int k;
		cin >> t >> k;
		int tval = getval(t);
		cout << ans[k][tval] << '\n';
	}
    return 0;
}
