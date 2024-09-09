#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string a, b, c;
	cin >> a >> b >> c;
	
	int n = a.size();
	
	vector<int> cnt(26), cnt_b(26), cnt_c(26);
	for (auto& ch: a) {
		cnt[ch - 'a']++;
	}
	for (auto& ch: b) {
		cnt_b[ch - 'a']++;
	}
	for (auto& ch: c) {
		cnt_c[ch - 'a']++;
	}
	
	int ans_b = 0, ans_c = 0;
	bool ok = true;
	for (int rep_b = 0; ok and rep_b <= n; rep_b++) {
		for (int i = 0; i < 26; i++) {
			if (cnt[i] < rep_b * cnt_b[i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			int rep_c = n;
			for (int i = 0; i < 26; i++) {
				if (cnt_c[i] > 0) {
					int left = cnt[i] - rep_b * cnt_b[i];
					rep_c = min(rep_c, left / cnt_c[i]);
				}
			}
			if (rep_b + rep_c > ans_b + ans_c) {
				ans_b = rep_b;
				ans_c = rep_c;				
			}
		}
	}
	
	for (int i = 0; i < ans_b; i++) {
		cout << b;
	}
	for (int i = 0; i < ans_c; i++) {
		cout << c;
	}
	for (int i = 0; i < 26; i++) {
		cout << string(cnt[i] - ans_b * cnt_b[i] - ans_c * cnt_c[i], 'a' + i);
	}
	
    return 0;
}
