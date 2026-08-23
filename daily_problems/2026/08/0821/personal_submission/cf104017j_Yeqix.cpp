#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	i64 w, l;
	cin >> w >> l;

	set<i64> ans = {1, 2};
	auto get = [&](i64 x)->void{
		for (i64 i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				ans.insert(i);
				ans.insert(x / i);
			}
		}
	};

	get(__gcd(__gcd(w - 2, w), l - 1));
	get(__gcd(__gcd(l - 2, l), w - 1));

	cout << ans.size() << " ";
	for (const auto& v : ans) {
		cout << v << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}