#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int la, ra, ta;
	int lb, rb, tb;
	
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	
	int l1 = ra - la + 1;
	int l2 = rb - lb + 1;
	int g = __gcd(ta, tb);
	
	int x = la - lb;
	x = (x % g + g) % g;
	// a区间相对与b区间起点位置x
	//     x    x + l1
	//  0   l2
	// x在b区间左端点的右侧/左侧两种情况
	// 1. x在lb'左侧 那么ra'要和rb'尽可能地靠近
	// ans = min((x+g) %g + l1, l2) - x
	// 2. x 在lb'右侧
	// a区间x - g往左边移动 和右端点l2尽可能地靠近
	// min(x-g+l1, l2) - 0
	cout << max({0, min(x + l1, l2) - x, min(x - g + l1, l2)});
	
    return 0;
}
