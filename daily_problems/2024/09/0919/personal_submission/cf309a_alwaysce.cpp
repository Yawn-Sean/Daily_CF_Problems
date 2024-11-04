#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, l, t;
	cin >> n >> l >> t;
	vector<int> a(n);
	for (auto& x: a) { cin >> x; }
	
	t *= 2;
	int d = t % l;
	double ans = 1.0 * n * (n - 1) * (t / l);
	
	// 寻找所有的pair 它们的距离 dis <= d 额外增加的部分
	for (int i = 0; i < n; i++) {
		a.push_back(a[i] + l);
	}
	
	for (int i = 0; i < n; i++) {
		// > a[i]+d的第一个位置 - 1 就是 <= d的最后一个位置
		// a[i] .... <=d  >d
		//     [i+1  r=it-1]
		ans += upper_bound(a.begin(), a.end(), a[i] + d) - 1 - a.begin() - i;
	}
	cout << setprecision(20) << ans / 4.0 << '\n';
    return 0;
}
