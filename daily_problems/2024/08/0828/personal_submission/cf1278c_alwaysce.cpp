#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(2 * n);
		int dif_init = 0;
		// numS - numB
		for (auto& v: a) { 
			cin >> v;
			if (v == 1) {
				dif_init++;
			} else {
				dif_init--;
			}
		}
		// 目标是 dif_init = dif_l + dif_r
		// 枚举右寻找左
		int dif_l = 0, dif_r = 0;
		map<int,int> lm;
		lm[0] = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == 1) {
				dif_l++;
			} else {
				dif_l--;
			}
			if (lm.count(dif_l) == 0) {
				lm[dif_l] = n - i; 
			}
		}
		
		int ans = 2 * n;
		for (int i = n; i < 2 * n; i++) {
			if (a[i] == 1) {
				dif_r++;
			} else {
				dif_r--;
			}
			
			int target_l = dif_init - dif_r;
			if (lm.count(target_l) != 0) {
				int leftL = lm[target_l];
				int rightL = i - n + 1;
				ans = min(ans, leftL + rightL);
			}
		}
		
		if (lm.count(dif_init)) {
			ans = min(ans, lm[dif_init]);
		}
		cout << ans << '\n';
	}
	
    return 0;
}
