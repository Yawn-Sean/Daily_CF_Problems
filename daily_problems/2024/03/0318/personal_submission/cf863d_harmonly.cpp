#include <iostream>
#include <array>
#include <vector>

using namespace std;

void solve() {
	int n, q, m;
	cin >> n >> q >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<array<int, 3>> qer(q);
	for (int i = 0; i < q; ++i) {
		cin >> qer[i][0] >> qer[i][1] >> qer[i][2];
		qer[i][1]--;
		qer[i][2]--;
	}
	vector<int> ans(m);
	for (int i = 0; i < m; ++i) {
		int b; cin >> b;
		--b;
		for (int j = q - 1; j >= 0; --j) {
			int type = qer[j][0], l = qer[j][1], r = qer[j][2];
			if (b < l || b > r) continue;
			if (type == 1) {
				b = (b == l ? r : b - 1);
			} else {
				b = r - b + l;
			}
		}
		ans[i] = a[b];
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << " \n"[i == m - 1];
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
