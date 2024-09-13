#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> w(n);
	for (auto &v : w) {
		cin >> v;
	}

	vector<int> freq(1 << n), val(1 << n);
	string s;
	for (int i = 0; i < m; i ++) {
		cin >> s;
		int mask = 0;
		for (int i = 0; i < n; i ++) {
			mask = mask * 2 + s[i] - '0';
		}
		freq[mask] ++;
	}

	for (int i = 1; i < 1 << n; i ++) {
		int x = i & -i;
		val[i] = val[i - x] + w[n - (32 - __builtin_clz(x))];
	}

	vector<vector<int>> f(101, vector<int>(1 << n));
	int msk = (1 << n) - 1;
	for (int i = 0; i < 1 << n; i ++) {
		for (int j = 0; j < 1 << n; j ++) {
			if (val[msk - (i ^ j)] <= 100) {
				f[val[msk - (i ^ j)]][i] += freq[j];
			}
		}
		for (int j = 1; j < 101; j ++) {
			f[j][i] += f[j - 1][i];
		}
	}

	int k;
	while (q -- ) {
		cin >> s >> k;
		int mask = 0;
		for (int i = 0; i < n; i ++) {
			mask = mask * 2 + s[i] - '0';
		}
		cout << f[k][mask] << endl;
	}
	return 0;
}
