#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> x(n);
	for (int i = 0; i < n; i++) { cin >> x[i]; }
	
	/*
	"Differ by at most one". 
	Note that the points chosen by an interval are consecutive.	
	

	*/
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
	}
	
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return x[i] < x[j];
	});
	
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[order[i]] = (i & 1);
	}
	for (auto& x: ans) {
		cout << x << ' ';
	}
    return 0;
}
