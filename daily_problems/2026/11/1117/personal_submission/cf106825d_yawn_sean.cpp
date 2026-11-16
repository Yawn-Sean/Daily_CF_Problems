#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	int l = 0, r = 1e9;

	while (l <= r) {
		int mid = (l + r) / 2;

		int soup = 0;
		long long dumpling = 0;
		bool flg = true;

		for (auto x: nums) {
			if (x < soup) {
				int w = min(soup / 2, (soup - x + 1) / 2);
				dumpling += w;
				soup = min(mid, soup - x + mid - 2 * w);
			}
			else {
				x -= soup;
				if (mid >= x) soup = mid - x;
				else {
					soup = 0;
					if (x - mid > dumpling) {
						flg = false;
						break;
					}
					dumpling -= x - mid;
				}
			}
		}

		if (flg) r = mid - 1;
		else l = mid + 1;
	}

	cout << l;

	return 0;
}