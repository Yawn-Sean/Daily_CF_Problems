#include<bits/stdc++.h>
using namespace std;

int n;
string s, t;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	cin >> T;
	
	while(T --) {
		cin >> n >> s >> t;
		int x = 0, y = 0;
		int d = 0;
		for(int i = 0; i < n; ++ i) {
			x += s[i] == '1';
			y += t[i] == '1';
			d += s[i] != t[i];
		}
		int ans = 1e9;
		if(x == y) ans = d;
		if(n - x + 1 == y) ans = min(ans, n - d);
		cout << (ans > n ? -1 : ans) << '\n';
	}
	return 0;
}
