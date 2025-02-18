#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	int n = (int)s.size();
	
	vector<vector<int>> pre(26, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			pre[j][i + 1] = pre[j][i] + ((s[i] - 'a') == j);
		}
	}
	
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int kind = 0;
		for (int j = 0; j < 26; j++) {
			if (pre[j][r] - pre[j][l - 1] > 0) {
				kind++;
			}
		}
		
		if (l == r or kind >= 3 or s[l - 1] != s[r - 1]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
    return 0;
}
