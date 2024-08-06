#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
	vector<pii> edg(m), weight(m);
    for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edg[i] = make_pair(u, v);
		weight[i] = make_pair(w, i);
	}
	sort(all(weight));
	UF dsu(n);
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		auto [w, id] = weight[i];
		auto [u, v] = edg[id];
		if (!dsu.sameSet(u, v)) {
			dsu.join(u, v);
			ans += max(0, w - k);
		}
	}
	if (ans == 0) {
		ans = k;
		for (int i = 0; i < m; i++) {
			ans = min(ans, (ll)abs(weight[i].first - k));
		}
	}
	cout << ans << endl;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
