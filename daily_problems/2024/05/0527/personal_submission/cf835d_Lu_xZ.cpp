#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 5005;

ll f[N][N], res[N], n;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> s, n = s.length();
	for(int i = 0; i < n; ++ i) f[i][i] = 1, ++ res[1];
	for(int len = 2; len <= n; ++ len) {
		for(int i = 0; i + len - 1 < n; ++ i) {
			int j = i + len - 1;
			if(len == 2) f[i][j] = (s[i] == s[j]) << 1;
			else {
				if(s[i] != s[j] || !f[i + 1][j - 1]) f[i][j] = 0;
				else f[i][j] = f[i][i + (j - i + 1) / 2 - 1] + 1;
			}
			++ res[f[i][j]];
		}
	}
	for(int i = n; i >= 1; -- i) res[i] += res[i + 1];
	for(int i = 1; i <= n; ++ i) cout << res[i] << ' ';
	return 0;
}
