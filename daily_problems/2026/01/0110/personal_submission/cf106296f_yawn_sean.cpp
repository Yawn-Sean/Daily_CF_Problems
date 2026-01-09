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

    while (t --) {
        int n;
        cin >> n;

        int v = (n + 1) >> 1;
        int l = 1, r = v - 1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            
            int v1, v2;
            cout << 2 << ' ' << 2 * mid - 1 << endl;
            cin >> v1;
            cout << 1 << ' ' << 2 * mid << endl;
            cin >> v2;

            if (v1 == v2) l = mid + 1;
            else r = mid - 1;
        }

        cout << 3 << ' ' << 2 * r - 1 << ' ' << 2 * r + 1 << endl;
    }

	return 0;
}