#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int h, q;
	cin >> h >> q;
	map<i64, int> mp;
	// 第h层 最左侧节点
	i64 L = (1ll << (h - 1));
	i64 R = (1ll << h);
	mp[L] = 0;
	mp[R] = 0;
	
	for (int i = 0; i < q; i++) {
		int idx, ans;
		i64 l, r;
		cin >> idx >> l >> r >> ans;
		r++;
		l <<= (h - idx);
		r <<= (h - idx);
		// [l, r) 上面存在答案
		if (ans == 1) {
			mp[l]++;
			mp[r]--;
		} else {
			// [L, l) [r, R)存在答案
			mp[L]++;
			mp[l]--;
			mp[r]++;
			mp[R]--;
		}
	}
	
	int cur = 0;
	i64 start = 0, last = (1ll << h) - 1;
	i64 cnt = 0;
	for (auto& pr: mp) {
		if (cur == q) {
			// [l, pr.first)上面都是满足要求的叶子可能答案
			cnt += pr.first - last;
			start = last;
		}
		cur += pr.second;
		last = pr.first;
	}
	if (cnt == 0) {
		cout << "Game cheated!";
	} else if (cnt == 1) {
		cout << start;
	} else {
		cout << "Data not sufficient!";
	}
	return 0;
}
