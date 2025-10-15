#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;


int main() {
	int n, k;
	cin >> n >> k;
	
	/*
	We only care about the richest and poorest people. 
	The numbers of their coins only increase / decrease with time.
	
	我们只需要关心最大的和最小的
	
	
	最穷的财富 单调不减
	最富有 单调不增 所以可以二分
	
	k次操作可以拆开成两边
	假设最穷的人有了m的coin 最少操作几次?
	*/
	i64 tot = 0;
	vector<i64> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		tot += c[i];
	}
	
	i64 l, r;
	i64 ans = 0;
	l = *min_element(c.begin(), c.end());
	r = tot / n;
	
	// 最穷的人在k次能到的状态
	while (l <= r) {
		i64 m = l + (r - l) / 2;
		i64 cur = 0;
		for (int i = 0; i < n; i++) {
			cur += max(m - c[i], 0ll);
			if (cur > k) {
				break;
			}
		}
		
		if (cur > k) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	ans -= r;
	
	// 最富有的人在k次能到的状态
	l = (tot + n - 1) / n;
	r = *max_element(c.begin(), c.end());
	while (l <= r) {
		i64 m = l + (r - l) / 2;
		i64 cur = 0;
		for (int i = 0; i < n; i++) {
			cur += max(c[i] - m, 0ll);
			if (cur > k) {
				break;
			}
		}
		if (cur > k) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	
	ans += l;
	cout << ans;
	return 0;
}
