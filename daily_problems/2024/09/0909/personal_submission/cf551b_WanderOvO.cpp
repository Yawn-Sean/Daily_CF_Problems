/*
相当于对 a 串进行重排，然后得到尽可能多的 b 串和 c 串
对 a, b, c 中的字符计数，然后考虑到底能匹配多少个 b 串和 c 串
枚举能匹配多少个 b，看还能匹配多少个 c 即可
*/

int T;
string a, b, c;
LL cnt[4][27];

void solve1() {
	cin >> a >> b >> c;
	for (auto ch : a) {
		cnt[0][ch - 'a']++;
	}
	for (auto ch : b) {
		cnt[1][ch - 'a']++;
	}
	for (auto ch : c) {
		cnt[2][ch - 'a']++;
	}
	LL max_cnt = 0, cnt1 = 0, cnt2 = 0;
	for (int i = 0; i <= a.size(); i++) {
		LL left_cnt[27] = {0};
		bool ok = true;
		for (int j = 0; j < 26; j++) {
			left_cnt[j] = cnt[0][j] - i * cnt[1][j];
			if (left_cnt[j] < 0) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			break;
		}
		LL c_cnt = a.size();
		for (int j = 0; j < 26; j++) {
			if (cnt[2][j] != 0) {
				c_cnt = min(c_cnt, left_cnt[j] / cnt[2][j]);
			}
		}
		if (c_cnt < 0) continue;
		if (c_cnt + i > max_cnt) {
			max_cnt = c_cnt + i;
			cnt1 = i;
			cnt2 = c_cnt;
		}
	}
	for (int i = 0; i < 26; i++) {
		cnt[0][i] -= cnt1 * cnt[1][i];
		cnt[0][i] -= cnt2 * cnt[2][i];
	}
	for (int i = 1; i <= cnt1; i++) {
		cout << b;
	}
	for (int i = 1; i <= cnt2; i++) {
		cout << c;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < cnt[0][i]; j++) {
			char ch = 'a' + i;
			cout << ch;
		}
	}
}   
