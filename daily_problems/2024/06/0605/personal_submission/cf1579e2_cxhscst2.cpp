#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 2e5 + 10;

int a[N];
int c[N];
int n;
int et = 0;
long long ans = 0;
map <int, int> mp;

int query(int x) {
	int ret = 0;
	for (; x; x -= x & -x) {
		ret += c[x];
	}

	return ret;
}

void update(int x, int val) {
	for (; x <= n; x += x & -x) {
		c[x] += val;
	}
}


void solve() {
	
	ans = 0;
	scanf("%d", &n);
	rep(i, 0, n + 2) c[i] = 0;

	mp.clear();
	rep(i, 1, n) {
		scanf("%d", a + i);
		mp[a[i]] = 0;
	}

	et = 0;
	for (auto& [key, value] : mp) {
		value = ++et;
	}

	rep(i, 1, n) {
		a[i] = mp[a[i]];
	}

	rep(i, 1, n) {
		int mn = query(a[i] - 1);
		int mx = query(n) - query(a[i]);
		
		ans += min(mn, mx);
		update(a[i], 1);
	}


	printf("%lld\n", ans);
}		

int T;

int main() {

	scanf("%d", &T);
	while (T--) {
		solve();
	}

	return 0;
}

