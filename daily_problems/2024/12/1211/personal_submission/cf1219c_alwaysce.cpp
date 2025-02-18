#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;


int main() {
	int L;
	string A;
	cin >> L >> A;
	
	// 不能长度整除
	int m = A.size();
	if (m % L != 0) {
		string base = "1";
		base += string(L - 1, '0');
		for (int i = 0; i <= m / L; i++) {
			cout << base;
		}
		cout << '\n';
		return 0;
	}
	
	auto get_next = [&](string& s) {
		vector<int> op;
		int x = s.size();
		int cur = 1, carry = 0;
		
		for (int i = x - 1; i >= 0; i--) {
			cur = (i == x - 1) + (s[i] - '0') + carry;
			carry = cur / 10;
			cur = cur % 10;
			op.push_back(cur);
		}
		
		if (carry) {
			op.push_back(carry);
		}
		
		string t;
		int y = op.size();
		for (int i = y - 1; i >= 0; i--) {
			t += ('0' + op[i]);
		}
		return t;
	};
	
	// 能整除
	string pre, ans;
	for (int i = 0; i < m; i += L) {
		string cur = A.substr(i, L);
		if (pre.empty()) {
			pre = cur; // 最高位截取
		} else if (cur > pre) {
			ans = get_next(pre); // 说明必须要把前面递增?
			break;
		} else if (cur < pre) {
			ans = pre;
			break;
		} else {
			// ===
		}
	}
	
	// 循环节全部都相等的情况
	if (ans.empty()) {
		ans = get_next(pre);	
	}
	
	// 特殊情况 进位之后长度溢出了
	int tmp = ans.size();
	if (tmp > L) {
		string base = "1";
		base += string(L - 1, '0');
		for (int i = 0; i <= m / L; i++) {
			cout << base;
		}
		cout << '\n';
	} else {
		for (int i = 0; i < m / L; i++) {
			cout << ans;
		}
		cout << '\n';
	}
	
	return 0;
}
