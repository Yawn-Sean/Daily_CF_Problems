#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;

	cin >> n >> s;

	vector<int> pref_ch(n + 1, 0);
	vector<int> pref_cnt(n + 1, 0);

	vector<int> suff_ch(n + 1, 0);
	vector<int> suff_cnt(n + 1, 0);

	int ch = 0, cnt = 0;
	long long cur = 0;

	for (int i = 0; i < n; i ++) {
		if (s[i] - 'a' != ch) ch = s[i] - 'a', cnt = 0;

		cur += 2 * cnt + 1;
		cnt ++;

		pref_ch[i + 1] = ch;
		pref_cnt[i + 1] = cnt;
	}

	ch = 0, cnt = 0;

	for (int i = n - 1; i >= 0; i --) {
		if (s[i] - 'a' != ch) ch = s[i] - 'a', cnt = 0;

		cnt ++;

		suff_ch[i] = ch;
		suff_cnt[i] = cnt;
	}

	long long ans = 0;

	for (int i = 1; i < n; i ++) {
		if (s[i] != s[i - 1]) {
			long long val = cur;

			val -= 2 * (s[i - 1] - 'a' == pref_ch[i - 1] ? pref_cnt[i - 1] : 0) + 1;
			val -= 2 * (s[i] - 'a' == suff_ch[i + 1] ? suff_cnt[i + 1] : 0) + 1;

			val += 2 * ((s[i] - 'a' == pref_ch[i - 1]) ? pref_cnt[i - 1] : 0) + 1;
			val += 2 * (s[i - 1] - 'a' == suff_ch[i + 1] ? suff_cnt[i + 1] : 0) + 1;

			ans = max(ans, val);
		}
	}

	cout << ans;

	return 0;
}