#include <bits/stdc++.h>
using LL = long long;
using namespace std;

void solve() {

	LL n,x,y,c;
	cin >> n >> x >> y >> c;

	if (c == 1) {
		cout << 0 << "\n";
		return;
	}

	auto check = [&] (LL m) {

		LL u,d,l,r,sum = m * 4 + m * (m - 1) * 2 + 1;
		// cout << sum << "\n";
		//-x
		if (m >= x) {
			LL val = m - x;
			sum -= (val + 1);

			//-y
			LL lim = min(y - 1 , val);
			if (1 <= lim) {
				sum -= (lim * (val + 1) - (1 + lim) * lim / 2);
			}
			lim = min(n - y , val);
			if (1 <= lim) {
				sum -= (lim * (val + 1) - (1 + lim) * lim / 2);
			}
		}
		//+x
		if (m >= (n + 1 - x)) {
			LL val = m - (n + 1 - x);
			sum -= (val + 1);

			LL lim = min(y - 1 , val);
			//(0 , val]
			if (1 <= lim) {
				sum -= (lim * (val + 1) - (1 + lim) * lim / 2);
			}
			lim = min(n - y , val);
			if (1 <= lim) {
				sum -= (lim * (val + 1) - (1 + lim) * lim / 2);
			}
		}
		//-y
		if (m >= y) {
			LL val = m - y;
			sum -= (val + 1);

			LL lim = min(x - 1 , val);
			//(0 , val]
			if (1 <= lim) {
				sum -= (lim * (val + 1) - (1 + lim) * lim / 2);
			}
			lim = min(n - x , val);
			if (1 <= lim) {
				sum -= (lim * (val + 1) - (1 + lim) * lim / 2);
			}
		}
		//+y
		if (m >= (n + 1 - y)) {
			LL val = m - (n + 1 - y);
			sum -= (val + 1);

			LL lim = min(x - 1 , val);
			//(0 , val]
			if (1 <= lim) {
				sum -= (lim * (val + 1) - (1 + lim) * lim / 2);
			}
			lim = min(n - x , val);
			if (1 <= lim) {
				sum -= (lim * (val + 1) - (1 + lim) * lim / 2);
			}
		}
		
		//-x,-y
		u = x , l = y;
		if (m >= u + l) {
			LL val = m - (u + l) + 1;
			sum -= (1 + val) * val / 2;
		}
		//-x,+y
		u = x , r = (n + 1) - y;
		if (m >= u + r) {
			LL val = m - (u + r) + 1;
			sum -= (1 + val) * val / 2;
		}
		//+x,-y
		d = (n + 1 - x) , l = y;
		if (m >= d + l) {
			LL val = m - (d + l) + 1;
			sum -= (1 + val) * val / 2;
		}
		//+x,+y
		d = (n + 1 - x) , r = (n + 1 - y);
		if (m >= d + r) {
			LL val = m - (d + r) + 1;
			sum -= (1 + val) * val / 2;
		}
		return (sum >= c);
	};

	LL l = 1 , r = 1E9 + 5;
	while (l < r) {
		LL md = (l + r) >> 1;
		if (check(md)) r = md;
		else l = md + 1;
	}

	cout << r << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
