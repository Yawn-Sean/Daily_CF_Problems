#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 5;

multiset<int> se;
map<int, set<int>> mp;

ll n, ans;

struct Fenwick_Tree {
	int t[N];
	void add(int p, int v) {
		while(p <= n) {
			t[p] += v;
			p += p & -p;
		}
	}
	int sum(int p) {
		int ret = 0;
		while(p) {
			ret += t[p];
			p -= p & -p;
		}
		return ret;
	}
	int get(int l, int r) {
		return sum(r) - sum(l - 1);
	}
} bit;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		int x; cin >> x;
		se.insert(x);
		mp[x].insert(i);
		bit.add(i, 1);
	}
	int cur = 1;
	for(int i = 1; i <= n; ++ i) {
		int x = *se.begin(); se.erase(se.begin());
		auto it = mp[x].lower_bound(cur);
		if(it == mp[x].end()) {
			ans += bit.get(cur, n);
			cur = 1;
			it = mp[x].begin();
		}
		ans += bit.get(cur, *it);
		cur = *it;
		mp[x].erase(it);
		bit.add(cur, -1);
	}
	cout << ans;
	return 0;
}
