#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int m[100010];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> bits;
	for (int j = (1 << k) - 1; j < (1 << 14); j ++) {
		int cnt = 0;
		for (int y = 0; y < 14; y ++) {
			cnt += (j >> y) & 1;
			if (cnt > k) break;
		}
		if (cnt == k) {
			bits.emplace_back(j);
		}
	}
	long long ans = 0;
	int x;
	for (int i = 0; i < n; i ++) {
		cin >> x;
		for (auto &b : bits) {
			ans += m[b ^ x];
		}
		m[x] ++;
	}
	memset(m, 0, sizeof m);
	cout << ans << endl;
	return 0;
}
