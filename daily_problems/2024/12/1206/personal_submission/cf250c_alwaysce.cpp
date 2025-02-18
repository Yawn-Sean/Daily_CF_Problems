#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	/*
		移动走一段之后的变化 = 
		a[l-1] == a[r+1] -> -2
		a[l-1] != a[r+1] -> -1
	*/
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<int> cnt(k + 1);
	int l = 0;
	while (l < n) {
		int r = l;
		while (r < n and a[l] == a[r]) {
			r++;
		}
		if (l-1 >= 0 and r < n) {
			cnt[a[l]] += (a[l-1] == a[r] ? 2 : 1);
		} else {
			cnt[a[l]] += 1;
		}
		l = r;
	}
	
	int mx = 0, ans = 0;
	for (int i = 1; i <= k; i++) {
		// cout << cnt[i] << ' ';
		if (cnt[i] > mx) {
			mx = cnt[i];
			ans = i;
		}
	}
	cout << ans;
	
	return 0;
}
