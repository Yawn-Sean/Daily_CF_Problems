#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

struct UF {
	std::vector<int> e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) std::swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};
int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (auto &a : A) std::cin >> a;

	std::vector<int> ord(N);
	std::iota(ord.begin(), ord.end(), 0);
	std::sort(ord.begin(), ord.end(), [&](const int &i, const int &j) -> bool {
		return A[i] < A[j];
	});

	int ans = 0;
	UF uf(N);

	std::multiset<int> ms;
	int max_len = 0;
	for (int i = 0; i < N; i++) {
		ms.insert(1);
		int k = A[ord[i]];
		
		auto unit = [&](int u, int v) -> void {
			int u_size = uf.size(u);
			int v_size = uf.size(v);

			ms.erase(ms.find(u_size));
			ms.erase(ms.find(v_size));

			uf.join(u, v);
			ms.insert(uf.size(u));
		};

		if (ord[i] && A[ord[i]-1] <= k) {
			unit(ord[i], ord[i]-1);
		}
		if (ord[i] + 1 < N && A[ord[i]+1] <= k) {
			unit(ord[i], ord[i]+1);
		}

		if (*ms.begin() == *ms.rbegin()) {
			if (max_len < ms.size()) {
				max_len = ms.size();
				ans = k+1;
			}
		}
	}

	std::cout << ans << '\n';
}
