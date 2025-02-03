#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	int n = s.size();
	bool find = false;
	
	for (int i = 1; i < n / 2; i++) {
		if (s[i] != s[i - 1]) { find = true; }
	}
	for (int i = n - n / 2; i < n - 1; i++) {
		if (s[i] != s[i + 1]) { find = true; }
	}
	
	if (!find) { cout << "Impossible"; }
	else {
		while (s.size() % 2 == 0) {
			// 寻找奇数 / 拆分出不对称的回文串
			string tmp = s.substr(0, (int)s.size() / 2);
			string tmp1 = tmp;
			reverse(tmp1.begin(), tmp1.end());
			
			if (tmp != tmp1) {
				cout << 1;
				return 0;
			}
			s = tmp;
		}
		cout << 2;
	}
	return 0;
}
