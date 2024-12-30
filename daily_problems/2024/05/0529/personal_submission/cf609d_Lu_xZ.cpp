#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5, M = 1e6;

int n, m, k, s, a[N] = {M}, b[N] = {M}, idxa, idxb, ia[N], ib[N];

struct Obj {
	int id; ll cost;
	bool operator < (const Obj& o) const {
		return cost < o.cost;
	}
} A[N], B[N];

int check(int lim) {
	ll res = 1e18;
	int x = -1;
	for(int i = 0; i <= min(k, idxa); ++ i) {
		if(k - i > idxb) continue;
		ll t = A[i].cost * a[lim] +  B[k - i].cost * b[lim];
		if(t < res) {
			res = t;
			x = i;
		}
	}
	if(res > s) return -1;
	return x;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m >> k >> s;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		if(a[i] < a[i - 1]) {
			ia[i] = i;
		}
		else {
			a[i] = a[i - 1];
			ia[i] = ia[i - 1];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		cin >> b[i];
		if(b[i] < b[i - 1]) {
			ib[i] = i;
		}
		else {
			b[i] = b[i - 1];
			ib[i] = ib[i - 1];
		}
	}
	for(int i = 1; i <= m; ++ i) {
		int t, c; cin >> t >> c;
		if(t == 1) 
			A[++ idxa] = {i, c};
		else
			B[++ idxb] = {i, c};
	}
	sort(A + 1, A + idxa + 1),  sort(B + 1, B + idxb + 1);
	for(int i = 1; i <= idxa; ++ i) A[i].cost += A[i - 1].cost;
	for(int i = 1; i <= idxb; ++ i) B[i].cost += B[i - 1].cost;
	
	int l = 1, r = n;
	while(l < r) {
		int mid = l + r >> 1;
		if(~ check(mid)) r = mid;
		else l = mid + 1;
	}
	if(int x = check(l); ~ x) {
		cout << l << '\n';
		for(int i = 1; i <= x; ++ i) cout << A[i].id << ' ' << ia[l] << '\n';
		for(int i = 1; i <= k - x; ++ i) cout << B[i].id << ' ' << ib[l] << '\n';
	}
	else cout << -1;
	return 0;
}
