#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

i64 inf_i64 = 2e15;
int inf_int = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int q;
	cin >> q;
	/*
	How can you find the first larger predecessor quickly? 
	Jump through the useless predecessors. 
	Then connect the vertice with its predecessor, 
	and you just need to calculate most steps that could be taken.
	
	学习倍增套路
	q<=400000
	
	parent[i][u] 2^i-th ancestor of u
	parent_weight[i][u]: 2^i往上的点里面最大权重
	
	chain[i][u]: 
	chain_weight[i][u] u节点 链上跳2^i步的sum
	*/
	
	
	int last = 0, cur = 1;
	vector<vector<int>> parent(20, vector<int>(q + 5)), parent_weight(20, vector<int>(q + 5)), chain(20, vector<int>(q + 5));
	vector<vector<i64>> chain_weight(20, vector<i64>(q + 5));
	
	for (int i = 0; i < 20; i++) {
		parent_weight[i][0] = inf_int;
		chain_weight[i][0] = inf_i64;
		if (i > 0) { chain_weight[i][1] = inf_i64; }	
	}
	chain_weight[0][1] = 0;
	
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			i64 p, q;
			cin >> p >> q;
			p ^= last;
			q ^= last;
			cur++;
			
			int u = cur;
			parent[0][u] = p; // u的直接父节点=p
			parent_weight[0][u] = q;
			chain[0][u] = p;
			chain_weight[0][u] = q;
			
			for (int i = 1; i < 20; i++) {
				p = parent[i - 1][u];
				parent[i][u] = parent[i - 1][p];
				parent_weight[i][u] = max(parent_weight[i - 1][u], parent_weight[i - 1][p]);
			}
			
			for (int i = 19; i >= 0; i--) {
				if (parent_weight[i][chain[0][u]] < q) {
					chain[0][u] = parent[i][chain[0][u]];
				}
			}
			
			for (int i = 1; i < 20; i++) {
				p = chain[i - 1][u];
				chain[i][u] = chain[i - 1][p];
				chain_weight[i][u] = chain_weight[i - 1][u] + chain_weight[i - 1][p];
				if (chain_weight[i][u] > inf_i64) {
					for (int j = i; j < 20; j++) {
						chain_weight[j][u] = inf_i64;
					}
					break;
				}
			}
			
		} else {
			i64 p, q;
			cin >> p >> q;
			p ^= last;
			q ^= last;
			
			last = 0;
			for (int i = 19; i >= 0; i--) {
				if (q >= chain_weight[i][p]) {
					q -= chain_weight[i][p];
					p = chain[i][p];
					last |= (1 << i);
				}
			}
			cout << last << '\n';
			
		}
	}
    return 0;
}
