#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<long long> s(n + 1);
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) std::cin >> a[i];

	auto query = [&](int l, int r) -> long long {
		if (r <= l + 1) return 0;
		return 1LL * std::min(a[l], a[r]) * (r - 1 - l) - (s[r - 1] - s[l]);
	};

	long long ans = 0;
	auto uuz = [&]() -> void {
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
		std::stack<int> sk;
		for (int i = 1; i <= n; sk.emplace(i), i++) {
			while(sk.size() && a[i] > a[sk.top()]) sk.pop();
			if (sk.size()) ans = std::max(ans, query(sk.top(), i));
		}
		std::reverse(a.begin() + 1, a.end());
	};

	uuz(); uuz();

	std::cout << ans;
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
