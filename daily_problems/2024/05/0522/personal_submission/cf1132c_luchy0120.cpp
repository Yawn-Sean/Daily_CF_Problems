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
#include <queue>
using namespace std;

int main() {
	
	int n, q;cin >> n >> q;
	vector<array<int, 2>> qs;
	for (int i = 0;i < q;++i) {
		int l,r;cin >> l >> r;
		qs.push_back({l,r});
	}
	int res = 0;
	for (int i = 0;i < q;++i) {
		vector<int> s(n+2);
		for (int j = 0;j < q;++j) {
			if (i == j) {
				continue;
			}
			s[qs[j][0]]++;
			s[qs[j][1] + 1]--;
		}
		vector<int> ones(n+1);
		int r = 0;
		for (int i = 1;i <= n;++i) {
			s[i] += s[i - 1];
			ones[i] = ones[i - 1];
			if (s[i] == 1) {
				ones[i] += 1;
			}
			if (s[i]) {
				r++;
			}
		}
		int m = n;
		for (int j = 0;j < q;++j) {
			if (i == j) {
				continue;
			}
			m = min(m, ones[qs[j][1]] - ones[qs[j][0] - 1]);
		}
		res = max(res, r - m);

	}
	cout << res;







	return 0;
}