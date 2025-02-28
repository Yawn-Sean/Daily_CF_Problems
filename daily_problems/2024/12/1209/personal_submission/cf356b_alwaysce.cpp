#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;


int main() {
	i64 n, m;
	cin >> n >> m;
	
	// sa = x * n
	// sb = y * m
	// 求sa-sb之间的hamming距离
	string x, y;
	cin >> x >> y;
	
	// Which pairs of positions can meet?
	// 例如对于a串的第一个位置 它能遇到b串的什么位置?
	// 考虑第一个串内位置p1 和 第二个串位置p2的字符匹配的位置?
	// p1, p1+k1s1
	// p2, p2+k2s2
	// p1-p2是gcd(s1, s2)的倍数
	
	// x=p1+k1s1 % lcm(s1,s2)
	// x, x+gcd(s1,s2), ... 接下来就是数这些位置对的相等/不相等数量
	i64 k1 = x.size(), k2 = y.size();
	i64 g = gcd(k1, k2);
	i64 ans = 0;
	
	// 位置差=gcd(k1,k2)的数对比较一次
	for (int i = 0; i < g; i++) {
		map<char, int> c;
		for (int j = i; j < k1; j += g) {
			c[x[j]]++;
		}
		for (int j = i; j < k2; j += g) {
			ans += c[y[j]];
		}
	}
	cout << (n * k1 - gcd(n, m) * ans);
	return 0;
}
