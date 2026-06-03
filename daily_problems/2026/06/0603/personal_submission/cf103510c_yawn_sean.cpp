#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		string s;
		cin >> s;

		vector<int> pos(26);
		for (int i = 0; i < 26; i ++) pos[s[i] - 'a'] = i;

		int pe = pos['e' - 'a'];
		int pz = pos['z' - 'a'];
		int pp = pos['p' - 'a'];
		int pc = pos['c' - 'a'];

		if (pe < pc && pz < pp && pp < pc) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}