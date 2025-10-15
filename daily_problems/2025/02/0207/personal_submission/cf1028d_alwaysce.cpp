#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	/*
		考虑Buying / Selling队列的实时价格
		buy只能加入小于目前最低sell的价格
		
		sell只能新加入价格>目前最高buying队列的价格
	
		ADD p
		ACCEPT p
		
		accept出现的时候才能确认
		>成交价格的都是sell
		<价格的都是buy
		
	*/
	set<int> st;
	int l = 0, r = 1e9;
	st.emplace(l), st.emplace(r);
	
	int v = 0;
	while (n--) {
		string op;
		int x;
		cin >> op >> x;
		if (op[1] == 'D') {
			st.emplace(x);
		} else {
			auto p = st.lower_bound(x);
			// 这一单既可以是buy也可以是sell *2
			if (x > l && x < r) { v++; }
			if (x < l || x > r) {
				cout << 0;
				return 0;
			}
			// 比l小的不能是sell 比r大的不能是buy
			p++;
			r = *p;
			p--; p--;
			l = *p;
			p++;
			st.erase(p); // 删除ACCEPT的订单
		}
	}
	
	i64 ans = 1ll;
	// 剩下的单子 前缀buy 后缀sell
	for (auto& x: st) {
		if (x > l && x < r) {
			ans++;
		}
	}
	// =可以随便选
	for (int i = 0; i < v; i++) {
		ans = (2ll * ans) % mod;
		
	}
	cout << ans;
	return 0;
}
