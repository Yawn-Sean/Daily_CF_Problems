#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		abcd
		(9-a)(9-b)(9-c)(9-d)
		
		x * (9..9-x)
		=> x * (10^k-1 - x) 找最大值
	*/
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	
	// 三段 每段=2*d
	// d最小是多少?
	auto check = [&](i64 L) {
		i64 last = x[0];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (x[i] - last > L) {
				cnt++;
				last = x[i];
			}
		}
		return cnt <= 3;
	};
	
	// 2d
	i64 left = 0, right = x[n - 1] - x[0] + 1ll;
	i64 ans = right;
	while (left < right) {
		i64 mid = (left + right) / 2;
		if (not check(mid)) {
			left = mid + 1;
		} else {
			right = mid;
			ans = mid;
		}
	}
	
	double ansl = 0.5 * ans;
	cout << fixed << setprecision(10) << ansl << '\n';
	
	i64 last = x[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (x[i] - last > ans) {
			cnt++;
			// [last, x[i]]
			cout << fixed << setprecision(10) << 1.0 * last + ansl << ' ';
			last = x[i];
		}
	}
	cout << fixed << setprecision(10) << 1.0 * last + ansl << ' ';
	// cout << cnt << '\n';
	while (cnt < 3) {
		cout << fixed << setprecision(10) << 1.0 * x[n - 1] << ' ';
		cnt++;
	}
	return 0;
}
