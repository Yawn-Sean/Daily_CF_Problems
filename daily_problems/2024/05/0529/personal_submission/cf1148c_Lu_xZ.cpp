#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 3e5 + 5;

int n, a[N], p[N];
vector<pair<int, int>> ans;

void __swap(int i, int j) {
	p[a[i]] = j;
	p[a[j]] = i;
	swap(a[i], a[j]);
	ans.push_back({i, j});
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		p[a[i]] = i;
	}
	for(int i = 1; i <= n; ++ i) {
		if(a[i] != i) {
			int t = p[i];
			if(t - i >= n / 2) {
				__swap(i, t);
				continue;
			}
			if(t <= n / 2) {
				__swap(t, n), __swap(i, n);
				continue;
			}
			if(i <= n / 2) {
				__swap(1, t);
				__swap(1, n);
				__swap(1, t);
				__swap(i, n);
			}
			else {
				__swap(1, t);
				__swap(1, i);
				__swap(1, t);
			}
		}
	}
	cout << ans.size() << '\n';
	for(auto &[l, r] : ans) cout << l << ' ' << r << '\n';
	return 0;
}
