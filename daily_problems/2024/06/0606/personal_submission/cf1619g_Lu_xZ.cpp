#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;
int fa[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if(x != y) fa[y] = x;
}

void solve() {
	int n, k; cin >> n >> k;
	struct Node {
		int v, id;
		Node(int v = 0, int id = 0)
			: v(v), id(id) {}
		bool operator < (const Node &o) const {
			return v < o.v;
		}
		bool operator > (const Node &o) const {
			return v > o.v;
		}
	};
	struct Bomb {
		int x, y, t;
	};
	map<int, vector<Node>> X;
	vector<Bomb> b(n);
	for(int i = 0; auto &[x, y, t] : b) {
		cin >> x >> y >> t;
		X[x].eb(y, i ++);
	}
	map<int, set<Node, greater<Node>>> Y;
	iota(fa, fa + n, 0);
	for(auto &[x, a] : X) {
		sort(a.begin(), a.end());;
		for(int i = 0; i < a.size(); ++ i) {
			if(i && a[i].v - a[i - 1].v <= k) {
				merge(a[i].id, a[i - 1].id);
			} 
			for(auto [nx, id] : Y[a[i].v]) {
				if(x - nx > k) break;
				merge(a[i].id, id);
			}
		}
		for(auto [y, id] : a) {
			Y[y].emplace(x, id);
		}
	}
	map<int, int> mi;
	for(int i = 0; i < n; ++ i) {
		if(mi.count(find(i))) {
			mi[find(i)] = min(mi[find(i)], b[i].t);
		}
		else mi[find(i)] = b[i].t;
	}
	vector<int> a;
	for(auto [v, t] : mi) a.eb(t);
	ranges::sort(a, greater<int>());
	for(int i = 0; i < a.size(); ++ i) {
		if(i >= a[i]) {
			cout << max(a[i], i - 1) << '\n';
			return;
		}
	}
	cout << a.size() - 1 << '\n';
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
