#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	/*
	考虑两首歌
	推了半天就有
	li(pi/1-pi) > lj(pj/1-pj)的不等式成立
	*/
	
	vector<int> l(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> p[i];
	}
	
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return l[i] * p[i] * (100 - p[j]) > l[j] * p[j] * (100 - p[i]);
	});

	i64 base = accumulate(l.begin(), l.end(), 0ll);
	
	double extra = 0;
	double pre = 0.0;
	
	for (int i = 0; i < n; i++) {
		extra += (1.0 - p[order[i]]/100.0) * pre;
		pre += (p[order[i]] / 100.0) * l[order[i]];
	}
	
	double ans = base;
	ans += extra;
	cout << fixed << setprecision(10) << ans;
	return 0;
}
