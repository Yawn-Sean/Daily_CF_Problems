#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
ll f[26][26], m;

string s, t;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(f, 0x3f, sizeof f);
	for(int i = 0; i < 26; ++ i) {
		f[i][i] = 0;
	}
	cin >> s >> t >> m;
	while(m --) {
		char a, b; int c;
		cin >> a >> b >> c;
		a -= 'a';
		b -= 'a';
		f[a][b] = min(f[a][b], ll(c));
	}
	for(int k = 0; k < 26; ++ k)
		for(int i = 0; i < 26; ++ i)
			for(int j = 0; j < 26; ++ j)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	if(s.length() != t.length()) {
		cout << -1;
		exit(0);
	}
	ll ans = 0;
	for(int i = 0; i < s.length(); ++ i) {
		int x = s[i] - 'a';
		int y = t[i] - 'a';
		ll tmp = 2e18;
		for(int j = 0; j < 26; ++ j) {
			ll val = f[x][j] + f[y][j];
			if(val < tmp) {
				tmp = val;
				s[i] = j + 'a';
			}
		}
		if(tmp > 1e18) {
			cout << -1;
			exit(0);
		}
		ans += tmp;
	}
	cout << ans << '\n' << s;
	return 0;
}
