#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int N;
	std::cin >> N;
	int S, T;
	std::cin >> S >> T;
	S--, T--;

	std::vector<std::vector<int> > adj(N);
	for (int i = 1; i < N; i++) {
		int u, v;
		std::cin >> u >> v;
		u--, v--;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::vector<int> vis_cnt(N);
	{

		std::vector<int> Q{S};
		vis_cnt[S]++;
		while (!Q.empty()) {
			std::vector<int> q;
			for (auto &u : Q) {
				for (auto &v : adj[u]) {
					if (vis_cnt[v]) {
						continue;
					}

					if (v == T) {
						continue;
					}
					vis_cnt[v]++;
					q.emplace_back(v);
				}
			}

			Q = std::move(q);
		}
	}

	{
		std::vector<int> Q{T};
		while (!Q.empty()) {
			std::vector<int> q;
			for (auto &u : Q) {
				for (auto &v : adj[u]) {
					if (vis_cnt[v]) {
						if (v == S) continue;
						if (vis_cnt[v] == 2) continue;
						vis_cnt[v]++;
						q.emplace_back(v);
					}
				}
			}
			Q = std::move(q);
		}
	}

	int X = std::count(vis_cnt.begin(), vis_cnt.end(), 1);
	int Y = std::count(vis_cnt.begin(), vis_cnt.end(), 0);
	std::cout << 1LL * N * (N-1) - 1LL * X * Y << '\n';
}
