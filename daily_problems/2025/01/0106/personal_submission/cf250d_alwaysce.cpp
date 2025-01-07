#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<int> ai(n), bi(m), li(m);
	for (auto& x: ai) { cin >> x; }
	for (auto& x: bi) { cin >> x; }
	for (auto& x: li) { cin >> x; }

	// |OAi| + |AiBj| + lj 
	auto dis = [&](int x, int y) -> long double {
		return sqrtl(1ll * a * a + 1ll * ai[x] * ai[x])
		+ sqrtl(1ll * (b - a) * (b - a) + 1ll * (bi[y] - ai[x]) * (bi[y] - ai[x]))
		+ li[y];
	};
	
	long double ans = 1e9;
	int idx1 = -1, idx2 = -1, i = 0;

	for (int j = 0; j < m; j++) {
		// 可以使用指针的单调移动
		while (i + 1 < n and (dis(i, j) > dis(i + 1, j))) {
			i++;
		}
		
		long double tmp = dis(i, j);
		if (tmp < ans) {
			ans = tmp;
			idx1 = i;
			idx2 = j;
		}
	}
	cout << idx1 + 1 << ' ' << idx2 + 1;
	return 0;
}
