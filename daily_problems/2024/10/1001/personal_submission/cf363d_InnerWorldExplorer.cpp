#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, a;
	cin >> n >> m >> a;
	vector<int> b(n), p(m);
	for (auto &x : b) {
		cin >> x;
	}
	for (auto &x : p) {
		cin >> x;
	}
	sort(p.begin(), p.end());
	sort(b.begin(), b.end());
	auto check = [&](int x) {
		int tot = 0, remain = a;
		for (int i = 0; i < x; i ++) {
			if (p[i] > b[n - x + i]) {
				remain -= p[i] - b[n - x + i];
				if (remain < 0) {
					return -1;
				}
				tot += b[n - x + i];
			}else{
				tot += p[i];
			}
		}
		return max(0, tot - remain);
	};
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid) != -1) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << " " << check(l) << endl;
	return 0;
}
