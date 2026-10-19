#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long a, s, l, r;
	cin >> a >> s >> l >> r;

	int ans = 0;

	for (int diff = 1; diff <= r - l; diff ++) {
		for (int length = 1; length * diff <= r - l; length ++) {
			int k = length + 1;
			if (s * 2 % k) continue;

			long long v = s * 2 / k - length * diff;

			if (v % 2 == 0) {
				long long vl = v / 2;
				long long vr = vl + length * diff;

				if (vl >= l && vr <= r && a >= vl && a <= vr && (a - vl) % diff == 0) ans ++;
			}
		}
	}

	if (s == a) ans ++;

	cout << ans;

	return 0;
}