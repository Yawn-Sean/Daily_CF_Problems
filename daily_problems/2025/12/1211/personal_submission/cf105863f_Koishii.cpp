#include <bits/stdc++.h>
using namespace std;


void soviet(){
	int n, q; std::cin >> n >> q;
	std::vector<int> a;
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x;
		if (a.empty() || x < a.back()) a.push_back(x);
	}
	while (q--) {
		int x; std::cin >> x;
		for (int i = 0; i < a.size();) {
			x %= a[i];
			int l = i + 1, r = a.size() - 1;
			while (l < r) {
				int mid = l + r >> 1;
				if (a[mid] <= x) r = mid;
				else l = mid + 1;
			}
			if (l < a.size() && a[l] <= x) i = l;
			else break;
		}
		std::cout << x << '\n';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(0);
	std::cin >> M_T;
	while(M_T--){ soviet(); }
	return 0;
}
