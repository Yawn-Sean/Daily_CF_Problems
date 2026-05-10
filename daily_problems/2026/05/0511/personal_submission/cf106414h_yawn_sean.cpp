#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

#include <cassert>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {
namespace internal {

struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    internal::scc_graph scc;
};

}  // namespace atcoder


using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string run;
	cin >> run;

	int t;
	cin >> t;

	if (run == "first") {
		while (t --) {
			int n, m;
			cin >> n >> m;

			vector<int> nums(n);
			for (auto &x: nums) cin >> x;

			vector<vector<int>> path(n);

			while (m --) {
				int u, v;
				cin >> u >> v;
				u --, v --;
				path[u].emplace_back(v);
				path[v].emplace_back(u);
			}

			vector<int> cols(n, 0);

			auto dfs = [&] (auto &self, int u) -> void {
				for (auto &v: path[u]) {
					if (!cols[v]) {
						cols[v] = cols[u] ^ 3;
						self(self, v);
					}
				}
			};

			for (int i = 0; i < n; i ++) {
				if (!cols[i]) {
					cols[i] = 1;
					dfs(dfs, i);
				}
			}

			int c1 = 0, c2 = 0;
			for (auto &x: cols) {
				if (x == 1) c1 ++;
				else c2 ++;
			}

			if (c1 <= c2) {
				cout << c1 << '\n';
				for (int i = 0; i < n; i ++) {
					if (cols[i] == 1) {
						cout << nums[i] << ' ';
					}
				}
				cout << '\n';
			}
			else {
				cout << c2 << '\n';
				for (int i = 0; i < n; i ++) {
					if (cols[i] == 2) {
						cout << nums[i] << ' ';
					}
				}
				cout << '\n';
			}
		}
	}
	else {
		while (t --) {
			int n, m, k;
			cin >> n >> m >> k;

			vector<int> nums(k);
			for (auto &x: nums) cin >> x;

			vector<vector<int>> path(n);

			while (m --) {
				int u, v;
				cin >> u >> v;
				u --, v --;
				path[u].emplace_back(v);
				path[v].emplace_back(u);
			}

			vector<int> cols(n, 0);

			auto dfs = [&] (auto &self, int u) -> void {
				for (auto &v: path[u]) {
					if (!cols[v]) {
						cols[v] = cols[u] ^ 3;
						self(self, v);
					}
				}
			};

			for (int i = 0; i < n; i ++) {
				if (!cols[i]) {
					cols[i] = 1;
					dfs(dfs, i);
				}
			}

			int c1 = 0, c2 = 0;
			for (auto &x: cols) {
				if (x == 1) c1 ++;
				else c2 ++;
			}

			vector<int> ans(n, 0);
			int pt = 0;

			if (c1 <= c2) {
				for (int i = 0; i < n; i ++) {
					if (cols[i] == 1) {
						ans[i] = nums[pt ++];
					}
				}
			}
			else {
				for (int i = 0; i < n; i ++) {
					if (cols[i] == 2) {
						ans[i] = nums[pt ++];
					}
				}
			}

			vector<vector<int>> choices(2, vector<int>(n, 0));

			for (int i = 0; i < n; i ++) {
				if (!ans[i]) {
					if (path[i].empty()) ans[i] = 1;
					else {
						vector<int> notvis(4, 1);
						for (auto &j: path[i]) notvis[ans[j]] = 0;

						vector<int> tmp;
						for (int j = 1; j <= 3; j ++) {
							if (notvis[j]) {
								tmp.emplace_back(j);
							}
						}

						if (tmp.size() == 1) ans[i] = tmp[0];
						else {
							choices[0][i] = tmp[0];
							choices[1][i] = tmp[1];
						}
					}
				}
			}

			atcoder::two_sat check(n);

			for (int i = 0; i < n; i ++) {
				if (!ans[i]) {
					for (auto &j: path[i]) {
						if (ans[j]) {
							for (int vi = 0; vi < 2; vi ++) {
								if (choices[vi][i] == ans[j]) {
									check.add_clause(i, vi ^ 1, i, vi ^ 1);
								}
							}
						}
						else {
							for (int vi = 0; vi < 2; vi ++) {
								for (int vj = 0; vj < 2; vj ++) {
									if (choices[vi][i] == choices[vj][j]) {
										check.add_clause(i, vi ^ 1, j, vj ^ 1);
									}
								}
							}
						}
					}
				}
			}

			check.satisfiable();
			auto check_ans = check.answer();

			for (int i = 0; i < n; i ++) {
				if (ans[i] == 0) {
					ans[i] = choices[check_ans[i]][i];
				}
			}

			for (auto &x: ans) cout << x << ' '; cout << '\n';
		}
	}

	return 0;
}