#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

template <typename T>
std::vector<int> z_algorithm(const T& s) {
	int n = static_cast<int>(s.size());
	if (n == 0) {
		return {};
	}

	std::vector<int> z(n, 0);
	int j = 0;
	for (int i = 1; i < n; ++i) {
		z[i] = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
		if (j + z[j] < i + z[i]) {
			j = i;
		}
	}
	z[0] = n;

	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        string s;
        cin >> s;

        int n = s.size();

        auto z = z_algorithm(s);
        reverse(s.begin(), s.end());
        auto rev_z = z_algorithm(s);
        reverse(rev_z.begin(), rev_z.end());

        long long ans = 0;
        for (int i = n - 1; i > 0; i --) {
            int x = min(i - 1, z[i]), y = min({i - 1, n - i, rev_z[i - 1]});
            ans += max(0, x + y - i + 1);
        }
        cout << ans << '\n';
    }

	return 0;
}