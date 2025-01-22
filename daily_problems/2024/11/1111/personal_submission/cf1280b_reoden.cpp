#include <bits/stdc++.h>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--) {
		int N, M;
		std::cin >> N >> M;
		std::vector grid(N, std::vector<int>(M));
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			std::string s;
			std::cin >> s;
			for (int j = 0; j < M; j++) {
				grid[i][j] = (s[j] == 'A');
				cnt += grid[i][j];
			}
		}

		if (cnt == 0) {
			std::cout << "MORTAL" << '\n';
			continue;
		}

		if (cnt == N * M) {
			std::cout << 0 << '\n';
			continue;
		}

		bool ok = false;
		for (const auto &_ : {0, M-1}) {
			cnt = 0;
			for (int i = 0; i < N; i++) { 
				cnt += grid[i][_];
			}
			// DEBUG << KV(_) << ' ' << KV(cnt) << ' ' << KV(ok) << '\n';
			if (cnt == N) {
				ok = true;
				break;
			}
		}

		for (const auto &_ : {0, N-1}) {
			cnt = 0;
			for (int i = 0; i < M; i++) {
				cnt += grid[_][i];
			}

			// DEBUG << KV(_) << ' ' << KV(cnt) << ' ' << KV(ok) << '\n';
			if (cnt == M) {
				ok = true;
				break;
			}
		}

		// DEBUG << KV(ok) << '\n';
		if (ok) {
			std::cout << 1 << '\n';
			continue;
		}

		for (int i = 1; i+1 < N; i++) {
			cnt = 0;
			for (int j = 0; j < M; j++) {
				cnt += grid[i][j];
			}
			if (cnt == M) {
				ok = true;
				break;
			}
		}

		for (int j = 1; j+1 < M; j++) {
			cnt = 0;
			for (int i = 0; i < N; i++) {
				cnt += grid[i][j];
			}
			if (cnt == N) {
				ok = true;
				break;
			}
		}
		if (grid[0][0] || grid[0][M-1] || grid[N-1][0] || grid[N-1][M-1] || ok) {
			std::cout << 2 << '\n';
		} else {
			for (int i = 0; i < N; i++) {
				ok |= (grid[i][0] || grid[i][M-1]);
			}
			for (int i = 0; i < M; i++) {
				ok |= (grid[0][i] || grid[N-1][i]);
			}

			std::cout << (4-ok) << '\n';
		}
	}
}
