#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		看每个圆被覆盖的次数
	*/
	int n;
	cin >> n;
	
	vector<array<int,3>> circles(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> circles[i][j];
		}
	}
	
	sort(circles.begin(), circles.end(), [&](array<int,3>& x, array<int,3>& y) {
		return x[2] > y[2];
	});
	
	vector<int> cnt(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			i64 d1 = 1ll * (circles[i][0] - circles[j][0]) * (circles[i][0] - circles[j][0]);
			i64 d2 = 1ll * (circles[i][1] - circles[j][1]) * (circles[i][1] - circles[j][1]);
			i64 r = 1ll * (circles[i][2] - circles[j][2]) * (circles[i][2] - circles[j][2]);
			if (d1 + d2 <= r) {
				cnt[i]++;
			}
		}
	}
	
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		ans += 1ll * (circles[i][2]) * (circles[i][2]) * ((max(0, cnt[i] - 1) & 1) ? -1 : 1);
	}
	
	cout << fixed << setprecision(10) << acosl(-1) * ans;
    return 0;
}
