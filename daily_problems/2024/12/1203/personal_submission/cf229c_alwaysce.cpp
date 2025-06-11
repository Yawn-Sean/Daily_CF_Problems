#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	/*
		Consider the basic characteristics of a triangle.	
		正难则反 数异色边三角形数量
		 一个点有两条异色边就产生了不符合要求的三角形
	*/
	i64 n, m;
	cin >> n >> m;
	vector<i64> cnt(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		++cnt[u];
		++cnt[v];
	}
	
	i64 tot = n*(n-1)*(n-2) / 6;
	i64 off = 0ll;
	for (int i = 0; i < n; i++) {
		off += 1ll * cnt[i] * (n - 1 - cnt[i]);
	}
	cout << tot - off / 2;
	return 0;
}
