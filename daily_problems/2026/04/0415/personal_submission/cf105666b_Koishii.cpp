#include <bits/stdc++.h>
using namespace std;

bool sol() {
	int n; std::cin >> n;
	std::multiset<int> se[2];
	for (int i = 0; i < n; i++) {
		int p, s; std::cin >> p >> s;
		se[s].insert(p);
	}

	std::vector<int> v[2];
	for (int i = 0; i < n; i++) {
		int p, s; std::cin >> p >> s;
		v[s].emplace_back(p);
	}
	for (int j = 0; j <= 1; j++) {
		std::sort(v[j].rbegin(), v[j].rend());
		for (int i = 0; i < v[j].size(); i++) {
			int p = v[j][i];
			auto it1 = se[j].lower_bound((p + 1) / 2);
			auto it2 = se[!j].lower_bound(p);
			if (it1 == se[j].end() && it2 == se[!j].end()) return 0;
			if (it1 == se[j].end()) {se[!j].erase(it2); continue;}
			if (it2 == se[!j].end()) {se[j].erase(it1); continue;}
			if (*it1 <= *it2 * 2) se[j].erase(it1);
			else se[!j].erase(it2);
		}
	}
	return 1;
}

void soviet() {
	if (sol()) std::cout << "YES\n";
	else std::cout << "NO\n";
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
