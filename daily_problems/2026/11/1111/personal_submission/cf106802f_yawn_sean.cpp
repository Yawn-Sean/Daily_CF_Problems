#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

mt19937 rng{random_device{}()};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int L = 1e9;

	uniform_int_distribution<int> rng_L(1, L);
	uniform_int_distribution<int> rng_1(0, 1);

	int n;
	cin >> n;

	auto query = [&] (int x) -> pair<bool, int> {
		cout << "? " << x << endl;
		string s; int d;
		cin >> s >> d;
		if (s == "YES") n --;
		return {s == "YES", d};
	};

	auto answer = [&] (int x) -> void {
		cout << "! " << x << endl;
		exit(0);
		return ;
	};

	int cur = rng_L(rng);
	auto [flg, d] = query(cur);

	while (n > 1) {
		int x = (cur - d) % L; x = (x + L - 1) % L + 1;
		int y = (cur + d) % L; y = (y + L - 1) % L + 1;

		int V = rng_1(rng) ? x : y;
		auto [nflg, nd] = query(V);
		flg = nflg, d = nd;

		if (!flg) answer(x ^ y ^ V);
		cur = V;
	}

	int x = (cur - d) % L; x = (x + L - 1) % L + 1;
	int y = (cur + d) % L; y = (y + L - 1) % L + 1;

	if (x == y) answer(x);
	else {
		auto dis = [&] (int x, int y) -> int {
			int w = abs(x - y);
			return min(w, L - w);
		};

		for (int i = 1; i <= L; i ++) {
			if (x != i && y != i && dis(i, x) != dis(i, y)) {
				if (query(i).second == dis(i, x)) answer(x);
				else answer(y);
			}
		}
	}

	return 0;
}