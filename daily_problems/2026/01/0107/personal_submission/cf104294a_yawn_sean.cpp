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

    int n, q;
    cin >> n >> q;

    vector<vector<int>> grid(n, vector<int>(n));
    for (auto &x: grid) for (auto &y: x) cin >> y;

    vector<vector<int>> saved(n, vector<int>(n * n + 1, n * n + 1));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            for (int k = 0; i + k < n && j + k < n; k ++) {
                saved[k][grid[i][j]] = min(saved[k][grid[i][j]], grid[i + k][j + k]);
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = n * n - 1; j >= 0; j --) {
            saved[i][j] = min(saved[i][j], saved[i][j + 1]);
        }
    }

    while (q --) {
        int a, b;
        cin >> a >> b;

        for (int i = n - 1; i >= 0; i --) {
            if (saved[i][a] <= b) {
                cout << (i + 1) * (i + 1) << '\n';
                break;
            }
        }
    }

	return 0;
}