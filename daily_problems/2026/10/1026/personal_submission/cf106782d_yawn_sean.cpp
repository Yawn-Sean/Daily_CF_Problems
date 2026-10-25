#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	cout << (1 << n + 1) - 2 << '\n';

	auto solve = [&] (auto &self, int x) -> void {
		if (x > n) return ;
		self(self, x + 1);
		cout << x << ' ';
		self(self, x + 1);
		cout << x << ' ';
	};

	solve(solve, 1);

	return 0;
}