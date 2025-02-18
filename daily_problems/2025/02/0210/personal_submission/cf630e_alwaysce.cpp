#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	i64 x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	// x为奇数 y中心位置都是奇数
	// x为偶数 y中心位置都是偶数
	// 每根竖线考虑一次答案(竖线上面 y1<= 中心 <= y2)的数量
	
	// x1, x2同奇偶
	// -分别求解奇数列 / 偶数列上面的数量
	i64 xl = x2 - x1 + 1;
	i64 yl = y2 - y1 + 1;
	
	cout << (xl+1)/2*(yl+1)/2 + (xl-1)/2 * (yl-1)/2;
	
	return 0;
}
