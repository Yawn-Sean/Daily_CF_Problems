#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

const int M = 1e6 + 5;
const long long inf = 4e18;
long long saved[M][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int cur = 0;
	for (auto &c: s) cur = (2 * cur + c - '0') % 3;

	if (cur == 0 || n % 2) cout << "JULIA";
	else cout << "GIOVANA";

	return 0;
}