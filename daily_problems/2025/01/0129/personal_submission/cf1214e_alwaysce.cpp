#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		连接2i - 2i-1的链条由di 根导线组成
		那么2i和2i-1就会打开
		2n-1根线段 + 2n个节点 = 1棵树
		即树上两点的距离需要恰好等于d[i]
	*/
	
	int n;
	cin >> n;
	vector<int> dist(n);
	for (auto& v: dist) {
		cin >> v;
	}
	
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return dist[i] > dist[j];
	});
	
	vector<int> chain;
	for (int i = 0; i < n; i++) {
		chain.push_back(2 * order[i] + 1);
	}
	
	// chain上所有的点成一条
	// 降序连点
	// u->v d1 d2, ...
	// 因为d<=n 所以链条上总能找到(? 中间就不用管 末尾需要延长)
	vector<pair<int,int>> outs;
	for (int i = 1; i < n; i++) {
		outs.emplace_back(chain[i - 1], chain[i]);
	}
	
	for (int i = 0; i < n; i++) {
		int pos = order[i];
		int d = dist[pos];
		
		// 目标顶点
		int u = 2 * pos + 2;
		int v = chain[i + d - 1]; // <= n
		outs.emplace_back(u, v);
		
		// 正好接到了末尾 链条扩展
		if (chain.back() == v) {
			chain.push_back(u);	
		}
	}
	
	for (auto& pr: outs) {
		cout << pr.first << ' ' << pr.second << '\n';
	}
	
	return 0;
}
