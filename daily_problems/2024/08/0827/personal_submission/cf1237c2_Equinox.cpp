#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 998'244'353;

void solve() {
	int n;

	std::cin >> n;

	std::vector<std::tuple<int, int, int, int>> points(n);
	for (int i = 0, a, b, c; i < n; ++ i)
		std::cin >> a >> b >> c, points[i] = { a, b, c, i + 1 };

	std::vector<int> buf2, buf3;

	auto help1 = [&](int l, int r) -> void{
		std::sort(points.begin() + l, points.begin() + r + 1, [](auto &x, auto &y) -> bool {
			return std::get<2>(x) < std::get<2>(y);
		});

		for (int i = l; i < r; i += 2)
			std::cout << std::get<3>(points[i]) << ' ' << std::get<3>(points[i + 1]) << '\n';

		if ((r - l + 1) & 1) {
			buf2.push_back(std::get<3>(points[r]));
		}
	};

	auto help2 = [&](int l, int r) -> void{
		buf2.clear();

		std::sort(points.begin() + l, points.begin() + r + 1, [](auto &x, auto &y) -> bool {
			return std::get<1>(x) < std::get<1>(y);
		});

		for (int i = l, j; i <= r; ) {
			j = i;
			while (j <= r && std::get<1>(points[j]) == std::get<1>(points[i]))
				++ j;	
			help1(i, j - 1);
			i = j;
		}

		for (int i = 0; i + 1 < buf2.size(); i += 2)
			std::cout << buf2[i] << ' ' << buf2[i + 1] << "\n";

		if ((r - l + 1) & 1)
			buf3.push_back(buf2.back());
	};

	std::ranges::sort(points);

	for (int i = 0, j; i < n; ) {
		j = i;
		while (j < n && std::get<0>(points[j]) == std::get<0>(points[i]))
			++ j;
		help2(i, j - 1);
		i = j;
	}

	for (int i = 0; i < buf3.size(); i += 2)
		std::cout << buf3[i] << ' ' << buf3[i + 1] << '\n';
}

auto FIO = []{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main () {
	#ifdef DEBUG
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int T = 1;
	// std::cin >> T;
	while (T --) {
		solve();
	}

	return 0;
}