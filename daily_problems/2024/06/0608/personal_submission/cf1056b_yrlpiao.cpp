#include <iostream>
#include <vector>
using namespace std;
#define int long long


void yrlpSolve() {
	int n, m; cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i * i + j * j) % m == 0) {
				ans += (n + m - i) / m * ((n + m - j) / m);
			}
		}
	}
	cout << ans;
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
