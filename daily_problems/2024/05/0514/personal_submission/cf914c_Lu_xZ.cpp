#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int P = 1e9 + 7;

int a[1005], k;
string s;

ll f[1005][1005];

ll dfs(int p, int cur, bool lim) {
	if(p == s.length()) {
		if(cur == 0) return 0;
		return (a[cur] + 1 == k);
	}
	if(!lim && f[p][cur] != -1) return f[p][cur];
	ll ret = 0;
	for(int i = 0; i <= (lim ? s[p] - '0' : 1); ++ i) {
		ret = (ret + dfs(p + 1, cur + i, lim && (i == s[p] - '0'))) % P;
	}
	if(!lim) f[p][cur] = ret;
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> s >> k;
	for(int i = 2; i <= 1000; ++ i) {
		a[i] = a[__builtin_popcount(i)] + 1;
	}
	memset(f, -1, sizeof f);
	int ans = dfs(0, 0, 1) - (k == 1) + (k == 0);
	if(ans < 0) ans += P;
	cout << ans;
	return 0;
}
