#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	// 找出最小的十进制数, 以便将其转换为以 n 为底数的系统, 从而得到 k 这个数
	int n;
	cin >> n;
	
	string k;
	cin >> k;
	//给你一个字符串表示的数字k 和对应进制n
	// 转回十进制下 数字最小是多少?
	// 注意: 切割一段 切出来的数字满足 0 <= num < k	
	// 从后往前贪心 取到最大 然后去掉0这个东西
	int r = k.size() - 1;
	
	i64 tmp = 1, ans = 0;
	while (r >= 0) {
		int l = r, cur = k[r] - '0';
		int v = 1;
		for (int i = r - 1; i >= max(0, r - 8); i--) {
			v *= 10;
			if (v * (k[i] - '0') + cur < n) {
				l = i;
				cur += v * (k[i] - '0');
			} else {
				break;
			}
		}
		// 去掉前导0
		while (l < r && k[l] == '0') {
			l++;
		}
		
		ans += 1ll * cur * tmp;
		tmp *= n;
		r = l - 1;
	}
	cout << ans;
	return 0;
}
