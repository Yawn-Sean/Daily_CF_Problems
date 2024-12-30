#include <bits/stdc++.h>

// #define DEBUG

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

constexpr int P = 1'000'000'007;
std::vector<int> get_next(const std::string &t) {
	int n = t.size();
	std::vector<int> nxt(n);
	
	nxt[0] = -1;
	int i = 0, j = -1;

	while (i + 1 < n) {
		if (j == -1 || t[i] == t[j]) {
			++ i, ++ j;
			nxt[i] = j;
		}
		else
			j = nxt[j];
	}

	return nxt;
}

void solve(){
	std::string s, t;
	std::cin >> s >> t;

	int n = s.size(), m = t.size();

	std::vector<int> nxt(get_next(t + "#" + s + "$")), pre(n, -1);

    for (int i = 0; i < n; i ++) {
        if (nxt[i + m + 2] == m) pre[i] = i;	// match
        else if (i) pre[i] = pre[i - 1];	// last match
    }

	std::vector<int> f(n), acc(n), aacc(n);

	for (int i = 0; i < n; ++ i) {
		if (~pre[i])	f[i] = pre[i] - m + 2; // [0, l]
		if (pre[i] >= m) {
			f[i] += aacc[pre[i] - m];
			if (f[i] >= P) f[i] -= P;
		}

		if (i) acc[i] = acc[i - 1], aacc[i] = aacc[i - 1];
		acc[i] += f[i];
		if (acc[i] >= P) acc[i] -= P;

		aacc[i] += acc[i];
		if (aacc[i] >= P) aacc[i] -= P;
	}

	std::cout << acc[n - 1];
}

auto FIO = []{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main() {
	#ifdef DEBUG
		freopen("in.txt", 'r', stdin);
		freopen("out.txt", 'w', stdout);
	#endif
	int t = 1;
	// std::cin >> t;
	while(t --)
		solve();
	return 0;
}