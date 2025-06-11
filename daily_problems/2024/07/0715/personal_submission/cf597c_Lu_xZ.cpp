#include<bits/stdc++.h>
#define eb emplace_back
#define ep emplace
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 5;

/*
f[i][j]   以 i 结尾长度为 j
*/

int n, k;
struct Fenwick {
	ll t[N];
	void add(int p, ll v) {
		while(p <= n) {
			t[p] += v;
			p += p & -p;
		}
	}
	ll sum(int p) {
		ll ret = 0;
		while(p >= 1) {
			ret += t[p];
			p -= p & -p;
		}
		return ret;
	}
} t[12];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k, ++ k;
	t[0].add(1, 1);
	for(int i = 1; i <= n; ++ i) {
		int x; cin >> x;
		for(int j = k; j >= 1; -- j) {
			t[j].add(x, t[j - 1].sum(x));
		}
	}
	cout << t[k].sum(n);
	return 0;
}
