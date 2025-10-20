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

	int t;
	cin >> t;

	map<long long, long long> mp;
	mp[12] = 48;
	mp[15] = 5055;
	mp[18] = 288;
	mp[21] = 7077;
	mp[24] = 8088;
	mp[27] = 3699;
	mp[36] = 48888;
	mp[45] = 5055555555ll;
	mp[54] = 222888888;
	mp[63] = 111888;
	mp[72] = 8088888888ll;
	mp[81] = 9099999999ll;

	while (t --) {
		long long n;
		cin >> n;

		auto pt = mp.find(n);
		if (pt != mp.end()) cout << pt->second << '\n';
		else {
			set<int> st;
			long long x = n;
			while (x) {
				st.insert(x % 10);
				x /= 10;
			}
			cout << (st.size() == 1 ? n : -1) << '\n';
		}
	}

	return 0;
}