#include <bits/stdc++.h>
using namespace std;


void soviet() {
	std::string s; std::cin >> s;

	bool flag = 0;
	for (auto &c : s) {
		if (c == '0') {
			flag = 1;
			break;
		}
	}
	if (!flag) {
		std::cout << 0 << '\n';
		return;
	}

	int n = s.size();
	std::vector<std::vector<int>> ne(10, std::vector<int>(n + 1, n));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 10; j++) {
			ne[j][i] = ne[j][i + 1];
		}
		ne[s[i] - '0'][i] = i;
	}

	std::vector<int> f(n + 1, 0);
	f[n] = -1;
	std::bitset<10> cnt;

	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		f[i] = res;
		cnt.set(s[i] - '0');
		if (cnt.all()) {
			res++;
			cnt.reset();
		}
	}
	int pos = 0;

	while (pos <= n) {
		int mi = n + 5, choice = -1;
		for (int i = (pos ? 0 : 1); i < 10; i++) {
			if (f[ne[i][pos]] < mi) {
				mi = f[ne[i][pos]];
				choice = i;
			}
		}
		std::cout << choice;
		pos = ne[choice][pos] + 1;
	}
	std::cout << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
