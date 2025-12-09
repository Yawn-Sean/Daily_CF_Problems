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

	auto query = [&] (long long x) -> bool {
		cout << "? " << x << endl;
		char c; cin >> c;
		return c == 'W';
	};

	auto answer = [&] (long long x) -> void {
		cout << "! " << x << endl;
	};

	while (t --) {
		auto orig = query(0);
		long long lbound, rbound;

		{
			long long length = 1;
			while (query(2 * length - 1) == orig) length <<= 1;

			long long l = length - 1, r = 2 * length - 2;
			while (l <= r) {
				long long mid = (l + r) / 2;
				if (query(mid) == orig) l = mid + 1;
				else r = mid - 1;
			}

			rbound = r;
		}
		
		{
			long long length = 1;
			while (query(-2 * length + 1) == orig) length <<= 1;

			long long l = -2 * length + 2, r = -length + 1;
			while (l <= r) {
				long long mid = (l + r) / 2;
				if (query(mid) == orig) r = mid - 1;
				else l = mid + 1;
			}
			
			lbound = l;
		}

		answer(rbound - lbound + 1);
	}

	return 0;
}