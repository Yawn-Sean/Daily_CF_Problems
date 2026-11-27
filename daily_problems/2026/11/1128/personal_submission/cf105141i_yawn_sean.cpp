#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s0, w0;
	cin >> n >> s0 >> w0;

	int M = 1e5;

	vector<long long> total(M + 1, 0);
	vector<int> cnt(M + 1, 0);

	vector<array<int, 3>> teams(n);
	for (auto &[s, w, d]: teams) {
		cin >> s >> w >> d;
		total[d] += d;
		cnt[d] ++;
	}

	for (int i = 1; i <= M; i ++) {
		total[i] += total[i - 1];
		cnt[i] += cnt[i - 1];
	}

	int cnt0 = cnt[s0] + 1;
	long long l = 1, r = w0 - total[s0];

	for (auto &[s, w, d]: teams) {
		auto cur = total[s];
		auto cur_cnt = cnt[s];

		if (d > s) {
			cur += d;
			cur_cnt ++;
		}

		if (w >= cur) {
			if (cur_cnt >= cnt0) {
				l = max(l, w - cur + 1);
				r = min(r, (long long)s);
			}
			else if (cur_cnt == cnt0 - 1) {
				l = max(l, min(w - cur + 1, (long long)s + 1));
			}
		}
	}

	cout << (l <= r ? "Yes" : "No");

	return 0;
}