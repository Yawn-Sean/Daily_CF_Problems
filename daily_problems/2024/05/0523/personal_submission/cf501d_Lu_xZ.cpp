#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;

int n, o[N], o1[N], p[N];

struct Segment_Tree {
	int t[N << 2];
	void init(int x = 1, int l = 1, int r = n) {
		t[x] = r - l + 1;
		if(l == r)  return;
		int mid = l + r >> 1;
		init(x << 1, l, mid), init(x << 1 | 1, mid + 1, r);
	}
	void add(int p, int v, int x = 1, int l = 1, int r = n) {
		if(l == r) {
			t[x] += v;
			return;
		}
		int mid = l + r >> 1;
		if(p <= mid) add(p, v, x << 1, l, mid);
		else add(p, v, x << 1 | 1, mid + 1, r);
		t[x] = t[x << 1] + t[x << 1 | 1];
	}
	int query(int p, int x = 1, int l = 1, int r = n) {
		if(p < 1) return 0;
		if(l == r) return t[x];
		int mid = l + r >> 1;
		if(p <= mid) return query(p, x << 1, l, mid);
		else return t[x << 1] + query(p, x << 1 | 1, mid + 1, r); 
	}
	int find(int rk, int x = 1, int l = 1, int r = n) {
		if(l == r) return l;
		int mid = l + r >> 1;
		if(rk <= t[x << 1]) return find(rk, x << 1, l, mid);
		else return find(rk - t[x << 1], x << 1 | 1, mid + 1, r);
	}
} T;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	T.init();
	for(int i = 1; i <= n; ++ i) {		// 排名从 0 开始
		int x; cin >> x;
		++ x;
		o[n - i] = T.query(x - 1);
		T.add(x, -1);
	}
	T.init();
	for(int i = 1; i <= n; ++ i) {
		int x; cin >> x;
		++ x;
		o1[n - i] = T.query(x - 1);
		T.add(x, -1);
	}
	for(int i = 0; i <= n - 1; ++ i) {
		o[i] += o1[i];
		if(o[i] > i) {
			o[i + 1] += o[i] / (i + 1);
			o[i] %= (i + 1);
		}
	}
	T.init();
	for(int i = n - 1; i >= 0; -- i) {
		int x = T.find(o[i] + 1);
		T.add(x, -1);
		cout << x - 1 << ' ';
	}
	return 0;
}
