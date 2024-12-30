#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
using namespace std;




int main() {
	int n, m;cin >> n >> m;
	vector<int> cnt(n+1);
	vector<int> step(n + 1,n);
	for (int i = 0;i < m;++i) {
		int a, b;cin >> a >> b;
		cnt[a]++;
		if (b > a) {
			step[a] = min(step[a], b - a);
		}
		else {
			step[a] = min(step[a], n - a + b);
		}
	}

	for (int i = 1;i <= n;++i) {
		int mk = i;
		int lst = 0;
		for (int g1 = 0;g1 < n;++g1) {
			if (cnt[mk] > 0) {
				lst = max(g1 + (cnt[mk] - 1) * n + step[mk], lst);
			}

			mk++;
			if (mk == n + 1) {
				mk = 1;
			}
		}
		cout <<  lst << " \n"[i == n];
	}

	return 0;
}