#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	auto query = [&](int x, int y) {
		cout << x << ' ' << y << '\n';
		cout.flush();
		string ans;
		cin >> ans;
		return ans[0] == 'b';
	};
	
	int n;
	cin >> n;
	
	int l = 0, r = 1e9;
	bool fl = query(r, r);
	for (int i = 0; i < n - 1; i++) {
		int m = (l + r) / 2;
		if (query(m, m) == fl) {
			// black
			// | b b
			r = m;
		} else {
			// w | b
			l = m;
		}
	}
	
	cout << l << ' ' << r << ' ' << r << ' ' << l;
    return 0;
}
