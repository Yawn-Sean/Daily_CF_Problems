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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int v, a, b, c, p1, p2, p3;
        cin >> v >> a >> b >> c >> p1 >> p2 >> p3;
        v *= 100;

        int inf = 1e9;
        vector<int> dp((p1 + 1) * (p2 + 1) * (p3 + 1), -inf);
        vector<int> resid((p1 + 1) * (p2 + 1) * (p3 + 1), 0);

        auto f = [&] (int i, int j, int k) -> int {
            return (i * (p2 + 1) + j) * (p3 + 1) + k;
        };

        for (int i = 0; i <= p1; i ++) {
            for (int j = 0; j <= p2; j ++) {
                for (int k = 0; k <= p3; k ++) {
                    if ((i * a + j * b + k * c) * 5 > v) {
                        int nx, ny, nmsk;
                        auto update = [&] () -> void {
                            if (dp[nmsk] < nx || (dp[nmsk] == nx && resid[nmsk] < ny)) {
                                dp[nmsk] = nx;
                                resid[nmsk] = ny;
                            }
                        };

                        nx = v - (i * a + j * b + k * c) * 5;
                        ny = 0;
                        nmsk = f(i, j, k);
                        update();

                        int x = dp[nmsk], y = resid[nmsk];
                        if (i < p1) {
                            nx = x, ny = y, nmsk = f(i + 1, j, k);
                            if (ny + a < 100) ny += a;
                            else {
                                nx = nx + v - (ny + a) * 5;
                                ny = 0;
                            }
                            update();
                        }

                        if (j < p2) {
                            nx = x, ny = y, nmsk = f(i, j + 1, k);
                            if (ny + b < 100) ny += b;
                            else {
                                nx = nx + v - (ny + b) * 5;
                                ny = 0;
                            }
                            update();
                        }

                        if (k < p3) {
                            nx = x, ny = y, nmsk = f(i, j, k + 1);
                            if (ny + c < 100) ny += c;
                            else {
                                nx = nx + v - (ny + c) * 5;
                                ny = 0;
                            }
                            update();
                        }
                    }
                }
            }
        }

        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }

	return 0;
}