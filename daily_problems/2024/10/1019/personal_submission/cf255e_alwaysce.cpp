#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<i64> a(n);
	for (auto& x: a) { cin >> x; }
	
	int MAXN = 1e6;
	vector<int> sg(MAXN, 0);
	map<int, int> cnt;
	
	int l = 0, r = 0;
	
	for (int i = 1; i < MAXN; i++) {
		// 相邻区间的MEX变化很小
		while (l * l * l * l < i) {
			cnt[sg[l]]--;		
			l++;
		}
		while (r * r <= i and r < i) {
			cnt[sg[r]]++;
			r++;
		}
		// 暴力找MEX=sg[i]
		while (cnt[sg[i]]) {
			sg[i]++;
		}
	}
	
	sort(a.begin(), a.end());
	cnt.clear();
	l = 0, r = 0;
	int ans = 0;
	
	// 更大的sg(x)怎么求? MEX([sg[l], ..., sg[r]]
	// 两个指针都是单调向右移动
	for (auto& x: a) {
		while (1ll * l * l * l * l < x) {
			cnt[sg[l]]--;
			l++;
		}
		while (1ll * r * r <= x and r < x) {
			cnt[sg[r]]++;
			r++;
		}
		int mex = 0;
		while(cnt[mex]) { mex++; }
		ans ^= mex;
	}
	
	cout << (ans != 0 ? "Furlo" : "Rublo");
    return 0;
}
