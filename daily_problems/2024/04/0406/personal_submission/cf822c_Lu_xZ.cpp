#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
#define pb emplace_back
using namespace std;
using ll = long long;
constexpr int N = 2e5 + 5;

int n, m, a[N], idx, root[N];

struct Node {
	int l, r;
	ll v;
} t[N * 4 + N * 17];


int build(int l = 1, int r = 2e5) {
	int x = ++ idx;
	t[x].v = 1e18;
	if(l == r) return x;
	int mid = l + r >> 1;
	t[x].l = build(l, mid), t[x].r = build(mid + 1, r);
	return x;
}

int update(int y, int p, ll v, int l = 1, int r = 2e5) {
	int x = ++ idx;
	t[x] = t[y];
	t[x].v = min(t[x].v, v);
	if(l == r) {
		return x;
	}
	int mid = l + r >> 1;
	if(p <= mid) t[x].l = update(t[y].l, p, v, l, mid);
	else t[x].r = update(t[y].r, p, v, mid + 1, r);
	return x;
}

ll query(int x, int p, int l = 1, int r = 2e5) {
	if(l == r) return t[x].v;
	int mid = l + r >> 1;
	if(p <= mid) return query(t[x].l, p, l, mid); 
	else return query(t[x].r, p, mid + 1, r);
}

vector<pair<int, int>> qr[N];
ll ans = 1e18;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		int l, r, v; cin >> l >> r >> v;
		qr[r].pb(l, v);
	}
	root[0] = build();
	for(int i = 1; i <= 2e5; ++ i) {
		root[i] = root[i - 1];
		for(auto [l, v] : qr[i]) {
			root[i] = update(root[i], i - l + 1, v);
			if(i - l + 1 < m) {
				ans = min(ans, v + query(root[l - 1], m - (i - l + 1)));
			}
		}
	}
	if(ans == 1e18) ans = -1;
	cout << ans;
	return 0;
}
