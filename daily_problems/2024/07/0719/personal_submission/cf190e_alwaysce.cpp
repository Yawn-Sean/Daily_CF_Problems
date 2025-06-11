#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	
	// last_idx数组用于存储每条边的“上一条”边的索引，形成一种链表结构
	// path数组用于存储每个节点的头节点索引，即每个节点的第一条出边在nodes数组中的索引。
	// nodes数组用于存储所有边的目标节点。
	std::vector<int> nodes, last_idx, path(n, -1);
	
	std::function<void(int,int)> add_edge = [&](int u, int v) {
		last_idx.push_back(path[u]);
		path[u] = (int)nodes.size();
		nodes.emplace_back(v);
	};
	
	while (m--) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		add_edge(u, v);
		add_edge(v, u);
	}
	
	std::unordered_set<int> st;
	for (int i = 0; i < n; i++) {
		st.emplace(i);
	}
	
	std::vector<std::vector<int> > ans;
	while (!st.empty()) {
		int u = *st.begin();
		st.erase(u);
		
		// stk里面存储的是当前等待搜索的节点 与u相连
		std::vector<int> stk = {u};
		std::vector<int> cur;
		while (!stk.empty()) {
			u = stk[stk.size() - 1];
			stk.pop_back();
			cur.push_back(u);
			
			// 排除与u不相邻的点
			std::unordered_set<int> new_st;
			int c = path[u];
			while (c >= 0) {
				if (st.find(nodes[c]) != st.end()) {
					// c-u原图不会相连
					st.erase(nodes[c]);
					new_st.emplace(nodes[c]);
				}
				// c=u的前一条边编号
				c = last_idx[c];
			}
			std::swap(st, new_st);
			for (auto& x: new_st) {
				stk.push_back(x);
			}
		}
		ans.push_back(cur);	
	}
	
	std::cout << ans.size() << '\n';
	for (auto& vl: ans) {
		std::cout << vl.size() << ' ';
		for (auto& v: vl) {
			std::cout << v + 1 << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
