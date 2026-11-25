#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << 15 << '\n';
	int cur = 2, total = 0;
	for (int i = 0; i < 15; i ++) {
		cout << cur << " \n"[i == 14];
		total += cur;
		cur *= 3;
	}

	cout << total << endl;

	auto query = [&] (int x) -> int {
		vector<int> pos, neg = {0};
		for (int i = 1; i <= 15; i ++) {
			if (x % 3 == 1) pos.emplace_back(i), x --;
			else if (x % 3 == 2) neg.emplace_back(i), x ++;
			x /= 3;
		}

		cout << "WEIGH\n";
		cout << neg.size() << '\n';
		for (int i = 0; i < neg.size(); i ++) cout << neg[i] << " \n"[i + 1 == neg.size()];
		cout << pos.size() << '\n';
		for (int i = 0; i < pos.size(); i ++) cout << pos[i] << " \n"[i + 1 == pos.size()];
		cout.flush();

		char c;
		cin >> c;

		if (c == '<') return -1;
		if (c == '>') return 1;
		return 0;
	};

	int t;
	cin >> t;

	while (t --) {
		int l = 1, r = total / 2;
		int ans = -1;

		while (l <= r) {
			int mid = (l + r) / 2;
			int res = query(mid);

			if (res == -1) r = mid - 1;
			else if (res == 1) l = mid + 1;
			else {
				ans = mid * 2;
				break;
			}
		}

		if (ans != -1) {
			cout << "VERDICT\n";
			cout << "EXACT\n";
			cout << ans << endl;
		}
		else {
			if (l > total / 2) {
				cout << "VERDICT\n";
				cout << "HEAVY" << endl;
			}
			else {
				cout << "VERDICT\n";
				cout << "EXACT\n";
				cout << l + r << endl;
			}
		}

		string s;
		cin >> s;
	}

	return 0;
}