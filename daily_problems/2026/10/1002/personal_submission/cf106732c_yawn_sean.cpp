#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pair<char, int>> readers(k);
	for (auto &[t, x]: readers) cin >> t >> x;

	sort(readers.begin(), readers.end(), [&] (pair<char, int> &x, pair<char, int> &y) {
		return x.second < y.second;
	});

	auto f = [&] () -> long double {
		long long tot = 0, cnt = 0;
		for (auto &[t, x]: readers) {
			cnt ++;
			if (t == 'S') tot += x;
			else tot = max(tot + 1, min(tot + n, cnt * x));
		}
		return (long double)tot / cnt;
	};

	auto mx = f();

	reverse(readers.begin(), readers.end());
	for (auto &[t, x]: readers) x = n + 1 - x;

	auto mn = f();
	mn = n + 1 - mn;

	cout << fixed << setprecision(15) << mn << ' ' << mx;

	return 0;
}