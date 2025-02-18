#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int b, d;
	cin >> b >> d;
	string a, c;
	cin >> a >> c;
	
	// S = a串重复b次
	// T = c串重复d次
	// 问S串的子序列中最多能够出现几次重复的T串?
	// 二分重复次数 尝试检查是否成立
	// 考虑[a, b]匹配c的情况
	
	// 假设在i位置 匹配了c串j位置
	// c串下一个位置j+1会在哪一个i'位置产生匹配呢?
	// 贪心的去找这个i'位置
	// 遍历a串 如果a串的当前字符ch匹配到了c串的to_idx[i]
	// c[to_idx[i]] = ch => to_idx[i]++
	int m = c.size();
	vector<int> to_idx(m), cnt(m, 0);
	iota(to_idx.begin(), to_idx.end(), 0);
	
	for (int i = 0; i < m; i++) {
		for (auto& ch: a) {
			if (ch == c[to_idx[i]]) {
				to_idx[i]++;
				// 找完了一轮
				if (to_idx[i] == m) {
					to_idx[i] = 0;
					cnt[i]++;
				}
			}
		}
	}
	
	int idx = 0, cur = 0;
	// a串 模拟b次 1e7
	// O(b + |a||c|)
	while (b--) {
		cur += cnt[idx];
		idx = to_idx[idx];
	}
	cout << cur / d << '\n';
	return 0;
}
