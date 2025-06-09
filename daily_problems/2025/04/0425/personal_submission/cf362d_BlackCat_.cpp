#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
struct DSU {
	std::vector<int> f, siz;
	std::vector<i64> val;

	DSU() {}
	DSU(int n) {
		init(n);
	}

	void init(int n) {
		f.resize(n);
		std::iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
		val.assign(n, 0);
	}

	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		siz[x] += siz[y];
		f[y] = x;
		val[x] += val[y];
		return true;
	}

	int size(int x) {
		return siz[find(x)];
	}
	i64 val1(int x) {
		return val[find(x)];
	}
};
void solve() {
	int n, m, p, q;
	std::cin >> n >> m >> p >> q;
	DSU d(n);
    std::vector<int> s(n,0);
	for (int i = 0; i < m; i++) {
		int u, v, z;
		std::cin >> u >> v>>z;
		u--;
		v--;
        d.merge(u, v);
		d.val[d.find(u)] += z;
	}
	std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> q1;
    
	for (int i=0;i<n;i++) {
        if(s[d.find(i)]==0){
		q1.push({d.val1(i), d.find(i)});
        }
        s[d.find(i)]=1;
	}
    
	if (q1.size() < q) {
		std::cout << "NO" << endl;
		return ;
	}

	std::vector<std::pair<int, int>> ans;
	while (q1.size() > q) {
        
		auto [x1, y1] = q1.top();
		q1.pop();
		auto [x2, y2] = q1.top();
		q1.pop();
		ans.push_back({y1 + 1, y2 + 1});
		d.merge(y1, y2);
		d.val[d.find(y1)] += std::min(x1 + x2 + 1, (i64)1e9);
		q1.push({d.val1(y1), d.find(y1)});
	}
	std::vector<int> vis(n, -1);
    if(ans.size()>p){
        std::cout<<"NO"<<endl;
        return ;
    }
   
	if (ans.size() < p) {
		for (int i = 0; i < n; i++) {
			if (vis[d.find(i)] != -1) {
				while (ans.size() < p) {
					ans.push_back({vis[d.find(i)] + 1, i + 1});
				}
				break;
			}
			else {
				vis[d.find(i)] = i;
			}
		}
	}
    
	if (ans.size() < p) {
		std::cout << "NO" << endl;
		return ;
	}
	std::cout << "YES" << endl;
	for (auto [x, y] : ans) {
		std::cout << x << " " << y << endl;
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
