#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;
int inf = 1e9;

struct DSU {

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		n个数字 a[1],...,a[n]
		每个数字表示shark每天移动的距离(a[i]各不相同)
	
		如果移动距离<k 那么shark的位置完全不变
		否则 shark就会变化位置
		
		shark不会从一个地点离开后再次回到这个地点
		因此 我们能够找到 移动距离<k的连续天数的区间段 每一段对应一个停留地点
		
		寻找一个最小的k 所有的区间长度相同	
		
		Actually, you need to calculate the number of connected components. 
		In what order should you merge them?
	*/
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<int> order(n), vis(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return a[i] < a[j];
	});
	
	vector<int> cnt(n + 1, 0);
	DSU d(n);
	int tot = 0, locations = 0, ans = 0;
	
	for (int idx = 0; idx < n; idx++) {
		int p = order[idx];
		if (p - 1 >= 0 and vis[p - 1]) {
			cnt[d.size(p - 1)]--;
			d.merge(p - 1, p);	
			--tot;
		}
		if (p + 1 < n and vis[p + 1]) {
			cnt[d.size(p + 1)]--;
			d.merge(p, p + 1);
			--tot;
		}
		
		vis[p] = 1;
		int tmp = d.size(p);
		++cnt[tmp];
		++tot;
		
		if (cnt[tmp] == tot and tot > locations)  {
			ans = a[p] + 1;
			locations = tot;
		}
	}
	
	cout << ans;
    return 0;
}
