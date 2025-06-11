#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int first = -1, last = -1;
	vector<int> pre(n + 1), suf(n + 1);
	for (int i = n - 1; i >= 0; i --) {
		if (s[i] == 'G') {
			suf[i] = suf[i + 1] + 1;
			if (last == -1) last = i;
		} else {
			suf[i] = 0;
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (s[i - 1] == 'G') {
			pre[i] = pre[i - 1] + 1;
			if (first == -1) first = i - 1;
		} else {
			pre[i] = 0;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i ++) {
		if (i >= 1) {
			int tmp = 0;
			if (s[i] == 'G') tmp ++;
			else {
				if (first != -1 && (first < i - 1 - pre[i] || last > i + suf[i + 1]))
					tmp ++;
			}
			ans = max(ans, pre[i] + suf[i + 1] + tmp);
		} else {
			ans = max(ans, pre[i + 1]);
		}
	}
	cout << ans << endl;
	return 0;
}
