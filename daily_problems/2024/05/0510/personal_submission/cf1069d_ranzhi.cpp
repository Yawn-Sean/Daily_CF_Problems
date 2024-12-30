#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

class UnionSet {
public :
	vector<int> fa, val;
	multiset<int, greater<int>> s;
	UnionSet(int t) :  fa(t + 1), val(t + 1) {
		for (int i = 0; i <= t; i++) fa[i] = i, val[i] = 1, s.insert(1);
	}

	int get(int x) {
		return fa[x] = (fa[x] == x ? x : get(fa[x]));
	}

	void merge(int a, int b) {
		int fa_a = get(a), fa_b = get(b);
		if (fa_a == fa_b) return;
		s.erase(s.find(val[fa_a]));
		s.erase(s.find(val[fa_b]));
		fa[fa_a] = fa_b;
		val[fa_b] += val[fa_a];
		s.insert(val[fa_b]);
	}
	
};

void solve() {
	int n, m; cin >> n >> m;
	UnionSet u(n + 1);
	vector<int> arr;
	int maxn = 0, k = 0;
	while (m--) {
		int a, b; cin >> a >> b;
		if (u.get(a) == u.get(b)) k += 1;
		else u.merge(a, b);
		if (k) {
			int cnt = -1, val = 0;
			for (auto& x : u.s) {
				if (cnt == k) break;
				cnt++;
				val += x;
			}
			arr.emplace_back(val - 1);
		}
		else arr.emplace_back(*u.s.begin() - 1);
	}
	for (auto& x : arr) cout << x << endl;
	cout << endl;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; t = 1;
	while (t--) solve();
	return 0;
}
