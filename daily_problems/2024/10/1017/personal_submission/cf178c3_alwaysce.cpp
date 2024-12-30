#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, m, n;
	cin >> h >> m >> n;
	
	vector<int> group_ids(h, -1), group_pos(h, -1);
	int k1 = 0, k2;
	for (int i = 0; i < h; i++) {
		if (group_ids[i] == -1) {
			k2 = 0;
			while (group_ids[i] == -1) {
				group_ids[i] = k1;
				group_pos[i] = k2;
				k2++;
				i = (i + m) % h;
			}
			k1++;
		}
	}
	
	vector<set<int>> groups(k1);
	map<int, int> mp;
	
	vector<int> tmp(k2);
	for (int i = 0; i < k1; i++) {
		for (int j = 0; j < k2; j++) {
			groups[i].insert(j);
		}
	}
	i64 ans = 0;
	while (n--) {
		char op;
		cin >> op;
		if (op == '+') {
			int idx, hash;
			cin >> idx >> hash;
			
			int g_id = group_ids[hash];
			int g_pos = group_pos[hash];
			int v = -g_pos;
			if (*groups[g_id].rbegin() >= g_pos) {
				g_pos = *groups[g_id].lower_bound(g_pos);
			} else {
				g_pos = *groups[g_id].begin();
			}
			
			v += g_pos;
			if (v < 0) {
				v += k2;
			}
			groups[g_id].erase(g_pos);
			mp[idx] = g_id * k2 + g_pos;
			ans += v;
		} else {
			int idx;
			cin >> idx;
			
			int g_id = mp[idx] / k2, g_pos = mp[idx] % k2;
			groups[g_id].insert(g_pos);
		}
	}
	
	cout << ans;
	return 0;
}
