#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> cnt(5, 0);
	for (int i = 0; i < n; i ++) {
		int x; cin >> x;
		cnt[x % 5] ++;
	}

	int orig = cnt[1] + 2 * cnt[2], res = -5 * n;

	for (int i = 0; i <= cnt[4] / 3; i ++) {
		int w3 = cnt[3], w4 = cnt[4] - 3 * i, cur = 2 * i;

		int w;
		w = min(w3, w4);
		w3 -= w, w4 -= w, cur += 2 * w;

		w = w3 / 2;
		w3 -= 2 * w, cur += w;

		cur -= 2 * w3 + w4;
		res = max(res, cur);
	}

	cout << orig + res;

	return 0;
}