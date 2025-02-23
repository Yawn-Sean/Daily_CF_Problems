#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	/*
		每一行可以移动的步长 = k的二进制子集长度
		求解 某一列能够最多有多少个元素?
		
		- 最低位=1 那么就是n(因为可以无限移动步长=1)
		- lowbit(z) > 1
		- 2 / 4 / 8 / ...
		- 取模分类
	*/
	
	vector<int> ls(n), rs(n);
	for (int i = 0; i < n; i++) {
		cin >> ls[i] >> rs[i];
	}
	
	vector<int> ans(30);
	for (int i = 0; i < 30; i++) {
		int lazy = 0; // 跳过检查的线段数量
		// 差分
		vector<pair<int,int>> prs;
		
		// 枚举每一个最低位长度L
		int L = (1 << i);
		for (int j = 0; j < n; j++) {
			int l = ls[j], r = rs[j];
			if (r - l + 1 >= L) {
				lazy++;
			} else {
				// 覆盖 差分
				l &= (L - 1); // [l&0x1111]
				r &= (L - 1); // [r&0x1111]
				prs.emplace_back(l, 1); // [l, r]+1
				prs.emplace_back(r+1, -1); // [r+1]-1
				if (l > r) {
					lazy++; // 跳过 因为一定覆盖了L(0)位置
				}
			}
		}
		
		prs.emplace_back(0, 0);
		prs.emplace_back(L, 0);
		sort(prs.begin(), prs.end());
		
		int cur = lazy;
		for (auto& pr: prs) {
			if (pr.first == L) { break; }
			cur += pr.second;
			ans[i] = max(ans[i], cur);
		}
	}
	
	int q;
	cin >> q;
	while (q--) {
		int v;
		cin >> v;
		int lb = __builtin_ctz(v); // 最低位的1
		cout << ans[lb] << '\n';
	}
	return 0;
}
