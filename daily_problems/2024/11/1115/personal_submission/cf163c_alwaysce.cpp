#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, v1, v2;
	i64 l;
	cin >> n >> l >> v1 >> v2;
	
	// 滑动窗口大小tmp(*(v1+v2))
	i64 tmp = l * v2;
	l *= (v1 + v2);
	
	// diff[r]: r位置为右端点能吃到多少巧克力
	// 右端点可以取值的范围(差分值=x的长度) 就是吃到x个的(概率*2l)
	map<i64,int> diff;
	for (int i = 0; i < n; i++) {
		i64 x;
		cin >> x;
		x *= (v1 + v2);
		if (x + tmp <= l * 2) {
			diff[x]++;
			diff[x+tmp]--;
		} else {
			diff[x]++;
			diff[l*2]--;
			diff[0]++;
			diff[x + tmp - l*2]--;
		}
	}
	diff[l*2] += 0;
	
	i64 last = 0;
	int cur_f = 0;
	vector<i64> ans(n + 1);
	for (auto& pr: diff) {
		i64 k = pr.first, freq = pr.second;
		// cout << k << ' ' << freq << '\n';

		ans[cur_f] += (k - last);
		cur_f += freq;
		last = k;
	}
	
	cout << fixed << setprecision(15);
	for (auto& x: ans) {
		cout << (long double)1.0 * x / (l * 2) << '\n';
	}
    return 0;
}
