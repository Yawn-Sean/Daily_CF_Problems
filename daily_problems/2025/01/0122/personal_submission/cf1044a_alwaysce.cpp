#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	/*
		竖线 等价于到达x>=val的地方需要多1次操作()
		横线等价于 [x1,x2]列到达顶部需要增加1
		对于给定的纵线 有一些横线是没有用的(右边界小于y) 这些不需要移动
		
	*/
	vector<int> v(n), h;
	for (auto&x:v) { cin >> x; }
	
	for (int i = 0; i < m; i++) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if (x1 == 1) {
			h.push_back(x2);
		}
	}
	sort(v.begin(), v.end());
	v.push_back(1e9);
	
	sort(h.begin(), h.end());
	
	m = h.size();
	int ans = n + m;
	int j = m - 1;
	for (int i = n; i >= 0; i--) {
		while (j >= 0 and h[j] >= v[i]) {
			j--;
		}
		ans = min(ans, i + m - j - 1);
	}
	
	cout << ans;
	return 0;
}
