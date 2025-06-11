#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m;
	string s;
	cin >> m >> s;
	int n = (int)s.size();
	for (int i = 0; i < 26; i ++) {
		int cur = -1;
		bool f = true;
		for (int j = 0; j < n; j ++) {
			if (s[j] - 'a' <= i) cur = j;
			else if (j - cur >= m) f = false;
		}

		if (f) {
			int cur = -1, near = -1;
			vector<int> ans(26);
			for (int j = 0; j < n; j ++) {
				if (s[j] - 'a' < i) {
					cur = j;
					ans[s[j] - 'a'] ++;
				} else if (s[j] - 'a' == i) {
					near = j;
				}
				if (j - cur == m) {
					ans[i] ++;
					cur = near;
				}
			}
			for (int i = 0; i < 26; i ++) {
				for (int j = 0; j < ans[i]; j ++) {
					cout << char(i + 'a');
				}
			}
			cout << endl;
			return 0;
		}
	}
	return 0;
}

