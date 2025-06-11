#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
	std::array<int, 8> s1, s2;
	// U D L R
	std::array<int, 4> dir1, dir2;
	dir1[0] = dir2[0] = -inf32, dir1[1] = dir2[1] = inf32, 
	dir1[2] = dir2[2] = inf32, dir1[3] = dir2[3] = -inf32;

	for (int i = 0; i < 4; ++ i) {
		std::cin >> s1[i * 2] >> s1[i * 2 + 1];
		dir1[0] = std::max(dir1[0], s1[i * 2 + 1]);
		dir1[1] = std::min(dir1[1], s1[i * 2 + 1]);
		dir1[2] = std::min(dir1[2], s1[i * 2]);
		dir1[3] = std::max(dir1[3], s1[i * 2]);
	}

	for (int i = 0; i < 4; ++ i) {
		std::cin >> s2[i * 2] >> s2[i * 2 + 1];
		dir2[0] = std::max(dir2[0], s2[i * 2] - s2[i * 2 + 1]);
		dir2[1] = std::min(dir2[1], s2[i * 2] - s2[i * 2 + 1]);
		dir2[2] = std::min(dir2[2], s2[i * 2] + s2[i * 2 + 1]);
		dir2[3] = std::max(dir2[3], s2[i * 2] + s2[i * 2 + 1]);
	}


	for (int i = 0; i < 4; ++ i) {
		int x = s1[i * 2], y = s1[i * 2 + 1];
		if (x + y >= dir2[2] && x + y <= dir2[3] && x - y <= dir2[0] && x - y >= dir2[1]) {
			std::cout << "YES\n";
			return;
		}

		x = s2[i * 2], y = s2[i * 2 + 1];
		if (x >= dir1[2] && x <= dir1[3] && y <= dir1[0] && y >= dir1[1]) {
			std::cout << "YES\n";
			return;
		}
	}

	int x = 0, y = 0;

	for (int i = 0; i < 4; ++ i) {
		x += s1[i * 2], y += s1[i * 2 + 1];
	}

	x /= 4, y /= 4;

	if (x + y >= dir2[2] && x + y <= dir2[3] && x - y <= dir2[0] && x - y >= dir2[1]) {
		std::cout << "YES\n";
		return;
	}

	x = 0, y = 0;

	for (int i = 0; i < 4; ++ i) {
		x += s2[i * 2], y += s2[i * 2 + 1];
	}

	std::cout << "NO\n";
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
	while (T --)
		solve();

	return 0;
}