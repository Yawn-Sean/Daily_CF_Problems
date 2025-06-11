#include <bits/stdc++.h>
using i64 = long long;

int at[5][5];
int bt[5][5];
int vis[5][5];

int apt[4][4] = {{0,0,0,0}, {0,0,0,1}, {0,1,0,0}, {0,0,1,0}};
int bpt[4][4] = {{0,0,0,0}, {0,0,1,0}, {0,0,0,1}, {0,1,0,0}};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 k, a, b;
	std::cin >> k >> a >> b;
	
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			std::cin >> at[i][j];
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			std::cin >> bt[i][j];
		}
	}
	
	// 模拟一次
	i64 awin = 0, bwin = 0;
	int cur_a = a, cur_b = b;
	memset(vis, -1, sizeof(vis));
	
	int tree = 0;
	while (tree < k and vis[cur_a][cur_b] == -1) {
		vis[cur_a][cur_b] = 1;
		// 记录得分
		awin += apt[cur_a][cur_b];
		bwin += bpt[cur_a][cur_b];
		
		// 转移到下一个状态		
		int na = at[cur_a][cur_b];
		int nb = bt[cur_a][cur_b];
		cur_a = na; cur_b = nb;
		tree++;
	}
	
	k -= tree;
	if (k <= 0) {
		std::cout << awin << ' ' << bwin << '\n';
		return 0;
	}
	
	// 在环里面的分数和
	int cyc = 0;
	std::vector<i64> cyc_sa{0}, cyc_sb{0};
	if (vis[cur_a][cur_b] == 1) {
		int nxt_a = cur_a;
		int nxt_b = cur_b;
		do {
			cyc++;
			// 记录环里面的分数
			cyc_sa.push_back(apt[nxt_a][nxt_b]);
			cyc_sb.push_back(bpt[nxt_a][nxt_b]);
			
			// 转移到下一个状态		
			int na = at[nxt_a][nxt_b];
			int nb = bt[nxt_a][nxt_b];
			nxt_a = na; nxt_b = nb;			
		} while (cur_a != nxt_a or cur_b != nxt_b);
	}
	for (int i = 1; i <= cyc; i++) {
		cyc_sa[i] += cyc_sa[i - 1];
		cyc_sb[i] += cyc_sb[i - 1];
	}

	i64 full = k / cyc;
	i64 left = k % cyc;
	awin += full * (cyc_sa[cyc]) + cyc_sa[left];
	bwin += full * (cyc_sb[cyc]) + cyc_sb[left]; 
	std::cout << awin << ' ' << bwin << '\n';
	return 0;
}
