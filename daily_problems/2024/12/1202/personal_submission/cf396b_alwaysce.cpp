#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

inline bool check(i64 x) {
	for (i64 i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	/*
		记录 v(n) 是 <=n 的最大质数
		u(n) 是 >n 的最小质数
		
		求出 for i = 2; i <= n; i++
			sum += 1 / (v(i) * u(i))
		
		以不可约分的分数形式给出
		即 cout << "p/q" 这种形式
		
		提示: A lot of u(i)v(i) is same!
		
		其实很像一个区间滑窗
		2, p[1], p[2], p[3]
		
		[p[1], p[2]) 这一段的v都是 p[1], u都是p[2]
		假设它的区间长度 = L
		贡献就是 L / (p[1] * p[2])
		
		不断地累加到n即可
		
		然后写了一下变成了
		(如果一整段都取满了) 
		1/p[1] - 1/p[2] + ...
		
	*/	
	
	
	while (t--) {
		i64 n;
		cin >> n;
		
		i64 x = n;
		while (not check(x)) { x--; }
		
		i64 y = n + 1;
		while (not check(y)) { y++; }
		// cout << x << ' ' << y << '\n';
		// ans = 1/2 - 1/y - (y-n-1) / xy
		
		i64 fenzi = 1ll * x * y - 2ll * x - 2ll * (y - n - 1);
		i64 fenmu = 2ll * y * x;
		i64 g = gcd(fenzi, fenmu);
        fenzi /= g;
        fenmu /= g;
        cout << fenzi << "/" << fenmu << '\n';
	}
	return 0;
}
