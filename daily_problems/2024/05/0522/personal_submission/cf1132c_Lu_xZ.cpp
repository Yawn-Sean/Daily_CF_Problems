#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 5005;

int n, m, l[N], r[N], s1[N], s2[N], a[N], ans, tot;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		cin >> l[i] >> r[i];
		++ a[l[i]], -- a[r[i] + 1];
	}
	for(int i = 1; i <= n; ++ i) {
		a[i] += a[i - 1];
		tot += (a[i] > 0);
		s1[i] = s1[i - 1] + (a[i] == 1);
		s2[i] = s2[i - 1] + (a[i] == 2);
	}
	auto q1 = [&](int l, int r) {return s1[r] - s1[l - 1];};
	auto q2 = [&](int l, int r) {return s2[r] - s2[l - 1];};
	
	
	for(int i = 1; i <= m; ++ i) {
		for(int j = i + 1; j <= m; ++ j) {
			int tmp = q1(l[i], r[i]) + q1(l[j], r[j]) + max(0, q2(max(l[i], l[j]), min(r[i], r[j])));
			ans = max(ans, tot - tmp);
		}
	}
	cout << ans;
	return 0;
}
