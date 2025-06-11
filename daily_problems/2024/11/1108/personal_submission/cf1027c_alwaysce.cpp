#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		考虑R 每个分量内部R的数量都是可以确定的
	*/
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		map<int,int> cnt;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			++cnt[a[i]];
		}
		// x=a/b, x+(1/x)最小的a,b就是答案
		// 越靠近1越好
		bool find = false;
		int pre = -1;
		int mn1 = -1, mn2 = -1;
		
		for (auto& pr: cnt) {
			int cur = pr.first, cur_cnt = pr.second;
			if (cur_cnt >= 4) {
				cout << cur << ' ' << cur << ' ' << cur << ' ' << cur << '\n';
				find = true;
				break;
			}
			if (cur_cnt >= 2) {
				if (mn1 != -1 and mn2 != -1 and pre != -1) {
					// 比较 (pre, cur) 和 (mn1, mn2) 谁更靠近1
					if (mn2 * pre > mn1 * cur) {
						mn1 = pre;
						mn2 = cur;
					}
				}
				if (pre != -1) {
					if (mn1 == -1 and mn2 == -1) {
						mn1 = pre;
						mn2 = cur;
					}
				}
				pre = cur;
			}
		}
		
		if (find) {
			continue;
		}
		cout << mn1 << ' ' << mn1 << ' ' << mn2 << ' ' << mn2 << '\n';
	}
	
	
    return 0;
}
