#include <iostream>
#include <vector>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int N, K;
	std::cin >> N >> K;
	std::vector<std::vector<int> > adj(N);
	std::vector<int> deg(N);
	for (int i = 1; i < N; i++) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}

	bool ok = true;
	if (K > N || N <= 3) {
		ok = false;	
	}

	std::vector<int> Q;
	for (int i = 0; i < N; i++) if (deg[i] == 1) Q.emplace_back(i);

	// WARNING: if remain only one vertex check k == K-1
	// if k == K-1 remain more then one vertex return false
	for (int k = 0; k < K && ok; k++) {
		std::vector<int> q;
		std::vector<int> cnt(N);
		for (auto &u : Q) {
			deg[u]--;
			// std::cerr << u << " \n"[u == Q.back()];
			for (auto &v : adj[u]) {
				cnt[v] += (deg[v] > 0);
				if (--deg[v] == 1) {
					q.emplace_back(v);
				}
			}
		}

		if (q.size() == 1U) {
			ok &= (k == K-1);
		}

		/* for (int i = 0; i < N; i++) {
			std::cerr << cnt[i] << " \n"[i == N-1];
		} */

		int ret = 0;
		for (int i = 0; i < N; i++) if (cnt[i]) {
			if (cnt[i] < 3 && k != K-1) {
				ok = false;
			}
			if (k == K-1) {
				ret += (cnt[i] >= 3);
				ok &= (cnt[i] >= 3);
			}
		}

		if (ret > 1) ok = false;

		Q.swap(q);
	}

	std::cout << (ok ? "Yes" : "No") << '\n';
}
