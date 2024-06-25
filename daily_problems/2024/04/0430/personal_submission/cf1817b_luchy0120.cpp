#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <string.h>
#include <array>
using namespace std;

vector<vector<int>> g;

const int N = 2001;
int vis[N];
int fa[N];
deque<int> q;
vector<array<int,2>> vs;

int main() {
	int t;cin >> t;

	for (int i = 0;i < t;++i) {
		int n,m;cin >> n >> m;
		g.clear();
		g.resize(n+1);
		
		for (int j = 0;j < m;++j) {
			int u, v;cin >> u >> v;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		int ok = 0;
		for (int j = 1;j <= n && !ok;++j) {
			int u = j;
			if (g[u].size() < 4) {
				continue;
			}
			memset(vis, 0, sizeof vis);
			memset(fa, 0, sizeof fa);
		
			for (auto & to : g[u]) {
				if (ok) {
					break;
				}
				if (!vis[to]) {
					fa[to] = u;
					q.clear();
					q.push_back(to);
					vis[to] = 1;
					while (q.size() > 0 && !ok) {
						int p = q.front();q.pop_front();
						for (auto v: g[p]) {
							if (!vis[v] && fa[p] != v) {
								if (v != u) {
									vis[v] = 1;
									fa[v] = p;
									q.push_back(v);
								}
								else {
									vs.clear();
									vs.resize(0);
									vs.push_back({p,u});
									int pp = p;
									while (fa[pp] != u) {
										vs.push_back({pp, fa[pp]});
										pp = fa[pp];
									}
									vs.push_back({pp,u});
									int ct = 0;
									for (auto to : g[u]) {
										if (to != p && to != pp) {
											vs.push_back({to,u});
											ct++;
											if (ct == 2) {
												break;
											}
										}
									}
									cout << "YES" << endl;
									cout << vs.size() << endl;

									for (auto& [l, h] : vs) {
										cout << l << " " << h << endl;
									}

									ok = 1;
									break;
								}
							}
						}
					}
				}
			}

			if (ok) {
				break;
			}

		}
		if (!ok) {
			cout << "NO" << endl;
		}
	}

	
	return 0;
}