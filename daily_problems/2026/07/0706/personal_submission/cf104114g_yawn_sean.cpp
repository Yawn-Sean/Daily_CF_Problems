#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> xs(n), rs(n);
	for (auto &x: xs) cin >> x;
	for (auto &r: rs) cin >> r;

	vector<long long> v_pos = {0}, v_neg;

	for (int i = 1; i < n; i ++) {
		if (i & 1) v_neg.emplace_back(xs[i] - xs[i - 1] - v_pos.back());
		else v_pos.emplace_back(xs[i] - xs[i - 1] - v_neg.back());
	}

	sort(rs.begin(), rs.end());

	auto check = [&] (long long x) -> void {
		vector<long long> tmp = {x};
		for (int i = 1; i < n; i ++) tmp.emplace_back(xs[i] - xs[i - 1] - tmp.back());

		auto to_check = tmp;
		sort(to_check.begin(), to_check.end());

		for (int i = 0; i < n; i ++) {
			if (to_check[i] != rs[i]) {
				return ;
			}
		}

		for (int i = 0; i < n; i ++) cout << tmp[i] << " \n"[i == n - 1];
		exit(0);
	};

	long long min_r = rs[0];
	long long v_mi;

	v_mi = *min_element(v_pos.begin(), v_pos.end());
	check(min_r - v_mi);
	v_mi = *min_element(v_neg.begin(), v_neg.end());
	check(v_mi - min_r);

	return 0;
}