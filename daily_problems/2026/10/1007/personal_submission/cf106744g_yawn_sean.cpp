#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, k;
	cin >> n >> k;

	long long total = k * (k + 1) / 2;
	long long base = (n - 1) / total + 1;

	vector<long long> ans(k, base);
	long long resid = base * total - n;

	for (int i = k - 1; i >= 0; i --) {
		long long v = min(base, resid / (i + 1));
		ans[i] -= v;
		resid -= (i + 1) * v;
	}

	for (int i = 0; i < k; i ++) cout << ans[i] << " \n"[i == k - 1];

	return 0;
}