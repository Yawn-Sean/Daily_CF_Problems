#include<bits/stdc++.h>
#define eb emplace_back
#define ep emplace
using namespace std;

using ll = long long;
constexpr int N = 5e5 + 5;

int n, a[N], t[N], p[N];

void init() {
	for(int i = 1; i <= n; ++ i) {
		t[i] = p[i] = 0;
	}
}
void add(int i, int v) {
	int x = a[i];
	while(x <= n) {
		if(v > t[x]) {
			t[x] = v, p[x] = i;
		}
		x += x & -x;
	}
}
auto query(int x) {
	int pos = 0, val = 0;
	while(x) {
		if(t[x] > val) {
			val = t[x], pos = p[x];
		}
		x -= x & -x;
	}
	return make_pair(val, pos);
}
#define ls x << 1
#define rs ls | 1

int mx[N << 2];
void build(int x = 1, int l = 1, int r = n) {
	if(l == r) {
		mx[x] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	mx[x] = max(mx[ls], mx[rs]);
}
int Max(int L, int R, int x = 1, int l = 1, int r = n) {
	if(L > R) return 0;
	if(L <= l && r <= R) return mx[x];
	int mid = l + r >> 1;
	int ret = 0;
	if(L <= mid) ret = max(ret, Max(L, R, ls, l, mid));
	if(R > mid) ret = max(ret, Max(L, R, rs, mid + 1, r));
	return ret;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	init(), build();
	for(int i = 1; i <= n; ++ i) {
		auto [val, pos] = query(a[i]);
		add(i, val + 1 + (Max(pos + 1, i - 1) >= a[i]));	
	}
	cout << query(n).first << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	cin >> T;
	
	while(T --) {
		solve();
	}
	return 0;
}
