#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int M = 1 << 5, INF = 0x3f3f3f3f;

int get(int x) {
	int ans = 0;
	for (int i = 0; i < 5; ++i) {
		ans += x >> i & 1;
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	map<char, int> mp;
	mp['R'] = 0;
	mp['G'] = 1;
	mp['B'] = 2;
	mp['Y'] = 3;
	mp['W'] = 4;

	set<int> st;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int col = mp[s[0]];
		int val = s[1] - '1';
		st.insert(col * 10 + val);
	}

	n = st.size();

	int ans = INF;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			set<int> vis;

			for (auto &x : st) {
				int curr = 0;
				int col = x / 10;
				int val = x % 10;

				if (i >> col & 1) {
					curr += (col + 1) * 10;
				}
				if (j >> val & 1) {
					curr += val + 1;
				}
				vis.insert(curr);
			}

			if (vis.size() == n) {
				int cnt = get(i) + get(j);
				ans = min(ans, cnt);
			}
		}
	}

	cout << ans << "\n";
	return 0;
}
