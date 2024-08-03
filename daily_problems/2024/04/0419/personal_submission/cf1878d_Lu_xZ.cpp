#include<bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rnd(time(0));
constexpr int N = 2e5 + 5;

int n, m, idx, root;

struct Node {
	int l, r, sz, val, pri;
	bool rev;
	void init(int v) {
		l = r = rev = 0, sz = 1;
		val = v;
		pri = rnd();
	}
} t[N];

void pushup(int x) {
	t[x].sz = t[t[x].l].sz + t[t[x].r].sz + 1;
}

void add_rev(int x) {
	t[x].rev ^= 1;
	swap(t[x].l, t[x].r);
}

void pushdown(int x) {
	if(t[x].rev) {
		add_rev(t[x].l), add_rev(t[x].r);
		t[x].rev = 0;
	}
}

void split(int x, int k, int &L, int & R) {
	if(!x) return L = R = 0, void();
	pushdown(x);
	if(t[t[x].l].sz < k) {
		L = x;
		split(t[x].r, k - t[t[x].l].sz - 1, t[x].r, R);
	}
	else {
		R = x;
		split(t[x].l, k, L, t[x].l);
	}
	pushup(x);
}

int merge(int L, int R) {
	if(!L || !R) return L + R;
	if(t[L].pri > t[R].pri) {
		pushdown(L);
		t[L].r = merge(t[L].r, R);
		pushup(L);
		return L;
	}
	else {
		pushdown(R);
		t[R].l = merge(L, t[R].l);
		pushup(R);
		return R;
	}
}

int New(int val) {
	t[++ idx].init(val);
	return idx;
}

void reverse(int l, int r) {
	if(l > r) swap(l, r);
	int x = 0, y = 0, z = 0;
	split(root, l - 1, x, y);
	split(y, r - l + 1, y, z);
	add_rev(y);
	root = merge(x, merge(y, z));
}

void output(string &s, int x) {
	if(!x) return;
	pushdown(x);
	output(s, t[x].l);
	cout << s[t[x].val];
	output(s, t[x].r);
}

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> l(k), r(k);
	for(auto &x: l) cin >> x;
	for(auto &x: r) cin >> x;
	
	root = idx = 0;
	for(int i = 0; i < n; ++ i) root = merge(root, New(i));
	
	int q; cin >> q;
	for(int i = 0; i < q; ++ i) {
		int x; cin >> x;
		auto j = upper_bound(l.begin(), l.end(), x) - l.begin() - 1;
		auto [a, b] = make_pair(x, r[j] + l[j] - x);
		reverse(a, b);
	}
	output(s, root);
	cout << '\n';
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
