#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	int len = (int)s.size();
	auto check = [&](int i, char c) {
		if (i - 2 >= 0 && (c == s[i - 2] || c == s[i - 1])) {
			return false;
		}
		if (i - 1 >= 0 && c == s[i - 1]){
			return false;
		}
		return true;
	};
	bool f = false;
	for (int i = len - 1; i >= 0; i --) {
		for (char c = s[i] + 1; c <= char(p + 'a' - 1) && !f; c ++) {
			if (i > 0 && c == s[i - 1])
				continue;
			if (i > 1 && c == s[i - 2])
				continue;
			s[i] = c;
			f = true;
		}
		if (f) {
			char c;
			for (int j = i + 1; j < len; j ++) {
				c = 'a';
				while (!check(j, c)) {
					c = char(c - 'a' + 1 + 'a');
				}
				if (c >= char(p + 'a')) {
					cout << "NO" << endl;
					return 0;
				}
				s[j] = c;
			}
			cout << s << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
