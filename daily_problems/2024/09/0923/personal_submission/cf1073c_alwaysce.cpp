#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	i64 x, y;
	cin >> x >> y;
	
	map<char,int> order;
	order['U'] = 1;
	order['D'] = -1;
	order['L'] = -1;
	order['R'] = 1;
	
	auto check = [&](i64 L) {
		i64 px = 0, py = 0;
		for (int i = L; i < n; i++) {
			if (s[i] == 'U' or s[i] == 'D') {
				py += order[s[i]];
			} else {
				px += order[s[i]];
			}
		}
		// [0, L - 1]可以任意修改
		// [L, n - 1]不变
		i64 need_x = x - px, need_y = y - py;
		// 至少需要这么多(方向完全一致)
		i64 mn = abs(need_x) + abs(need_y);
		// +2 +4可以
		if (L >= mn and L % 2 == mn % 2) {
			return true;
		}
		
		for (int r = L; r < n; r++) {
			if (s[r] == 'U' or s[r] == 'D') {
				py -= order[s[r]];
			} else {
				px -= order[s[r]];
			}
			
			if (s[r - L] == 'U' or s[r - L] == 'D') {
				py += order[s[r - L]];
			} else {
				px += order[s[r - L]];
			}
			
			need_x = x - px, need_y = y - py;
			i64 mn = abs(need_x) + abs(need_y);
			if (L >= mn and L % 2 == mn % 2) {
				return true;
			}
		}
		return false;
	};
	
	
	i64 left = 0, right = n + 1;
	i64 ans = n + 1;
	while (left < right) {
		i64 mid = (left + right) / 2;
		if (not check(mid)) {
			left = mid + 1;
		} else {
			right = mid;
			ans = mid;
		}
	}
	
	cout << ((ans <= n) ? ans : -1) << '\n';
	return 0;
}
