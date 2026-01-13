#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

vector<int> prep(string s) {
	int n = s.size();
	vector<int> kmp(n);
	int j = 0;

	for (int i = 1; i < n; i ++) {
		while (j && s[j] != s[i]) j = kmp[j - 1];
		if (s[j] == s[i]) j ++;
		kmp[i] = j;
	}

	return kmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		string s;
		cin >> n >> s;

		s += ' ';
		for (int i = 0; i < n; i ++) s += s[i] ^ 1;

		auto res = prep(s);
		for (int i = n + 1; i <= 2 * n; i ++)
			cout << res[i] << ' ';
		cout << '\n';
	}

	return 0;
}