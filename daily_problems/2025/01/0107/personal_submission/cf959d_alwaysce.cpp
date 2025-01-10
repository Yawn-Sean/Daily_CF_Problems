#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int mx = 2e6;
	
	vector<int> fac(mx + 1);
	iota(fac.begin(), fac.end(), 0);
	for (int i = 2; i <= mx; i++) {
		if (fac[i] == i) {
			for (int j = i; j <= mx; j += i) {
				fac[j] = i;
			}
		}
	}
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x: a) { cin >> x; }
	
	vector<int> used(mx + 1), ans(n, -1);
	for (int i = 0; i < n; i++) {
		int v = a[i];
		bool find = true;
		while (v > 1) {
			int p = fac[v];
			while (v % p == 0) {
				v /= p;
			}
			if (used[p]) {
				find = false;
			}
		}
		
		if (find) {
			ans[i] = a[i];
			v = a[i];
			while (v > 1) {
				int p = fac[v];
				while (v % p == 0) {
					v /= p;
				}
				used[p] = 1;
			}
		} else {
			while (true) {
				a[i]++;
				v = a[i];
				find = true;
				while (v > 1) {
					int p = fac[v];
					while (v % p == 0) {
						v /= p;
					}
					if (used[p]) {
						find = false;
					}
				}
				if (find) { break; }
			}
			
			ans[i] = a[i];
			v = a[i];
			while (v > 1) {
				int p = fac[v];
				while (v % p == 0) {
					v /= p;
				}
				used[p] = 1;
			}
			
			int pt = 2;
			for (int j = i + 1; j < n; j++) {
				while (fac[pt] != pt or used[pt]) {
					pt++;
				}
				ans[j] = pt;
				used[pt] = 1;
			}
			break;
		}
	}
	for (auto& x: ans) {
		cout << x << ' ';
	}
	return 0;
}
