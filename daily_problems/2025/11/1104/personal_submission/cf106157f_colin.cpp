#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int, int> tii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

constexpr int N = 5007;

int h[N], f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

int main() {
	int n = rd(), m = rd();
	rep(i, 1, n) h[i] = rd();
	vector<tii> e;
	rep(i, 1, m) {
		int u = rd(), v = rd();
		e.eb(max(h[u], h[v]), min(h[u], h[v]), u, v);
	}
	sort(all(e));
	sort(h + 1, h + 1 + n);
	int ans = 1e9;
	rep(i, 1, n) {
		rep(j, 1, n) f[j] = j;
		for (auto [w1, w2, x, y] : e) 
			if (w2 >= h[i]) {
				f[find(x)] = find(y);
				if (find(1) == find(2)) {
					ans = min(ans, w1 - h[i]);
					break;
				}
			}
		if (find(1) != find(2)) break;
	}
	printf("%d\n", ans);
	return 0;
}