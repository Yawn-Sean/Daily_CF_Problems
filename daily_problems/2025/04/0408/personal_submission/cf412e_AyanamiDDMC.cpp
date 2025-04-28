#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

bool check1(char c) {
	return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_'));
}

bool check2(char c) {
	return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool check3(char c) {
	return (c >= 'a' && c <= 'z');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	string s;
	cin >> s;

	int n = s.size();
	LL ans = 0;

	for (int i = 0; i < n; ++i) {
		// 邮箱可能的起始位置
		if (s[i] == '@') {
			int l = i;
			int cl = 0;

			while (l > 0 && check1(s[l - 1])) {
				l--;
				// 累计小写字母数量
				cl += check3(s[l]);
			}

			// @后面是字母或者数字
			int r = i;
			while (r + 1 < n && check2(s[r + 1])) r++;

			// 统计'.'后面的字母数量
			if (r > i && r + 1 < n && s[r + 1] == '.') {
				r++;
				int p = r;
				int cr = 0;

				while (p + 1 < n && check3(s[p + 1])) {
					p++;
					cr++;
				}
				ans += (LL) cl * cr;
			}
		}
	}

	cout << ans << "\n";
	return 0;
}
