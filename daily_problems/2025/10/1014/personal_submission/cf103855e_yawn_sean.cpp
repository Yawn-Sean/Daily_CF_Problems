#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n, t;
	cin >> n >> t;

	string s;
	cin >> s;

	set<char> st;
	int l = 0;

	auto solve = [&] (int l, int r) -> void {
		map<char, vector<int>> mp;

		for (int i = l; i < r; i ++)
			mp[s[i]].emplace_back(i);
		
		if (mp.find('P') == mp.end()) {
			for (int i = l; i < r; i ++) s[i] = 'R';
			int cur = l - 1;
			for (auto &p: mp['S']) {
				cur = max(cur + 1, p - t);
				s[cur] = 'S';
			}
		}

		else if (mp.find('R') == mp.end()) {
			for (int i = l; i < r; i ++) s[i] = 'S';
			int cur = l - 1;
			for (auto &p: mp['P']) {
				cur = max(cur + 1, p - t);
				s[cur] = 'P';
			}
		}

		else {
			for (int i = l; i < r; i ++) s[i] = 'P';
			int cur = l - 1;
			for (auto &p: mp['R']) {
				cur = max(cur + 1, p - t);
				s[cur] = 'R';
			}
		}
	};

	for (int i = 0; i < n; i ++) {
		st.insert(s[i]);
		if (st.size() == 3) {
			solve(l, i);
			l = i;
			st = {s[i]};
		}
	}

	solve(l, n);

	cout << s;

    return 0;
}