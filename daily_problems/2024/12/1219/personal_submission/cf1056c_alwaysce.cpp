#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	int r = 2 * n;	
	vector<int> p(r);
	for (auto& x: p) { cin >> x; }
	
	vector<int> contract(r, -1), chosen(r, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		contract[a] = b;
		contract[b] = a;
	}
	
	int t, last = -1;
	cin >> t;
	for (int x = 0; x < n; x++) {
		if (t == 2) {
			cin >> last;
			--last;
			chosen[last] = 2;
		}
		
		if (last != -1 and contract[last] != -1 and not chosen[contract[last]]) {
			cout << contract[last] + 1 << endl;
			chosen[contract[last]] = 1;
		} else {
			int v = -1, idx = -1;
			for (int i = 0; i < 2 * n; i++) {
				if (contract[i] != -1 and not chosen[i] and p[i] - p[contract[i]] > v) {
					v = p[i] - p[contract[i]];
					idx = i;
				}
			}
			if (idx == -1) {
				for (int i = 0; i < 2 * n; i++) {
					if (not chosen[i] and p[i] > v) {
						v = p[i];
						idx = i;
					}
				}
			}
			cout << idx + 1 << endl;
			chosen[idx] = 1;
		}

		if (t == 1) {
			cin >> last;
			--last;
			chosen[last] = 2;
		}
	}
	
	return 0;
}
