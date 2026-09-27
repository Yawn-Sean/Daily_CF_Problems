#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, idx;
		cin >> n >> idx;

		int ans = 0;

		while (true) {
			if (idx & 1) {
				ans += idx / 2 + 1;
				break;
			}

			ans += n / 2;
			idx /= 2;
			if (n & 1) idx ++;
			n -= n / 2;
		}

		cout << ans << '\n';
	}

	return 0;
}