#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> bin_2s;

	for (int i = 0; i < m; i ++) {
		string s;
		cin >> s;

		char source = 'A', tmp = 'C', target = 'B';
		string bin_2;

		for (int j = n - 1; j >= 0; j --) {
			if (s[j] == target) {
				bin_2 += '1';
				swap(source, tmp);
			}
			else {
				bin_2 += '0';
				swap(tmp, target);
			}
		}

		bin_2s.emplace_back(bin_2);
	}

	cout << max_element(bin_2s.begin(), bin_2s.end()) - bin_2s.begin() + 1;

	return 0;
}