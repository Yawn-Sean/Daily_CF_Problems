#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	int n = s.size();
	
	if (n % 2) {
		int half = (n + 1) / 2;
		cout << string(half, '4') << string(half, '7');
	} else {
		int half = n / 2;
		int c4 = half, c7 = half;
		if (string(c7, '7') + string(c4, '4') < s) {
			cout << string(c4 + 1, '4') << string(c7 + 1, '7');
			return 0;
		} 
		
		bool find = false;
		string ans = s;
		
		for (int i = 0; i < n; i++) {
			if (find) {
				// 这里后面就先4后7的填写就行
				if (c4 > 0) {
					ans[i] = '4';
					--c4;
				} else {
					ans[i] = '7';
					--c7;
				}
			} else {
				if (s[i] == '4') {
					if (c4 > 0) {
						ans[i] = '4';
						--c4;
					} else {
						// 7 > 4
						ans[i] = '7';
						--c7;
						find = true;
					}
				} else if (s[i] > '4' and s[i] <= '7' and c7 > 0) {
					if (s[i] != '7') {
						find = true;
					}
					ans[i] = '7';
					--c7;
				} else if (s[i] > '4') {
					// >7 7还有 | >4 7用完了
					// 找到前面最靠后的一个4 用7换掉
					find = true;
					for (int j = i - 1; j >= 0; j--) {
						if (ans[j] == '4') {
							if (c7 > 0) {
								++c4;
								--c7;
								ans[j] = '7';
								i = j;
								break;
							} else {
								++c4;
							}
						} else {
							++c7;
						}
					}
				} else {
					// 填任何一个都可以了
					find = true;
					if (c4 > 0) {
						ans[i] = '4';
						--c4;
					} else {
						ans[i] = '7';
						--c7;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}
