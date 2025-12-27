#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void manacher(vector<int> &v, vector<int> &radii) {
	int n = v.size();
	int last = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (last + radii[last] > i)
			radii[i] = min(last + radii[last] - i, radii[last - (i - last)]);
		else
			radii[i] = 1;
		while (v[i + radii[i]] == v[i - radii[i]])
			++radii[i];
		if (i + radii[i] > last + radii[last])
			last = i;
	}
}

void soviet() {
	int n0; cin >> n0;
	vector<int> a(n0);
	for (int i = 0; i < n0; ++i) cin >> a[i];

	int n = 2 * n0 + 1;
	vector<int> v(n);
	v[0] = -2;
	v[n - 1] = -1;
	for (int i = 0; i < n0; ++i) v[2 * i + 1] = a[i];

	vector<int> radii(n, 1);
	manacher(v, radii);

	for (int i = 1; i < n - 1; ++i) {
		radii[i] -= (radii[i] & 1) ^ (!!v[i]);
	}

	vector<long long> diff(n + 2, 0);
	for (int i = 1; i < n - 1; ++i) {
		int R = radii[i];
		diff[i - R] += 1;
		diff[i + 1] -= 2;
		diff[i + R + 2] += 1;
	}

	for (int c = 0; c < 2; ++c) {
		for (int i = 1; i < n; ++i) {
			diff[i] += diff[i - 1];
		}
	}

	for (int i = 0; i < n; ++i) {
		diff[i] >>= 1;
	}

	long long ans = 0;
	for (int i = 1; i < n - 1; i += 2) {
		ans = (ans + diff[i] % MOD * a[i / 2]) % MOD;
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) { soviet(); }
	return 0;
}
