#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

const int MAX = (int)2E9;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	for (auto &x : a) {
		cin >> x;
	}
	vector<int> t(k);
	for (auto &x : t) {
		cin >> x;
	}
	vector<int> L(n, MAX), R(n, MAX);
	for (int i = 0; i < k; i ++) {
		int tmp = a[i] - 1;
		L[tmp] = R[tmp] = t[i];
	}

	for (int i = 1; i < n; i ++) {
		L[i] = min(L[i - 1] + 1, L[i]);
	}

	for (int i = n - 2; i >= 0; i --) {
		R[i] = min(R[i + 1] + 1, R[i]);
	}

	for (int i = 0; i < n; i ++) {
		cout << min(L[i], R[i]) << " ";
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q --) {
		solve();
	}
	return 0;
}
