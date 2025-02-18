#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

template <class T> bool ckmax(T &a, const T &b) {
	return a < b ? a = b, 1 : 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, h;
	cin >> n >> h;
	vector<pair<int, int>> seg(n);
	int x1, x2;
	for (int i = 0; i < n; i ++) {
		cin >> x1 >> x2;
		seg[i] = {x1, x2};
	}
	vector<int> gap(n);
	for (int i = 1; i < n; i ++) {
		gap[i] = gap[i - 1] + seg[i].first - seg[i - 1].second;
	}

	int ans = 0;
	for (int i = 0; i < n; i ++) {
		auto it = lower_bound(gap.begin() + i, gap.end(), gap[i] + h);
		if (it == gap.end()) { //to the end
			ckmax(ans, seg.back().second + h - (gap[n - 1] - gap[i]) - seg[i].first);
		} else {
			if (*it == h + gap[i]) { // == 0
				ckmax(ans, seg[it - gap.begin()].first - seg[i].first);
			} else { // cannot cross certain gap
				ckmax(ans, seg[it - gap.begin() - 1].second - seg[i].first + h - (gap[it - gap.begin() - 1] - gap[i]));
			}
		}
	}
	cout << ans << endl;
	return 0;
}
