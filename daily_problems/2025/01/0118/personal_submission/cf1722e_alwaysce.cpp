#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	vector<vector<i64>> preS(1005, vector<i64>(1005));
	auto reset = [&]() {
		for (int i = 0; i < 1005; i++) {
			for (int j = 0; j < 1005; j++) {
				preS[i][j] = 0;
			}
		}
	};
	
	auto update = [&]() {
		for (int i = 1; i < 1005; i++) {
			for (int j = 1; j < 1005; j++) {
				preS[i][j] += preS[i - 1][j] + preS[i][j - 1] - preS[i - 1][j - 1];
			}
		}
	};
	
	while (t--) {
		int n, q;
		cin >> n >> q;
		reset();
		
		for (int i = 0; i < n; i++) {
			int h, w;
			cin >> h >> w;
			preS[h][w] += 1ll * h * w;
		}
		update();
		
		for (int i = 0; i < q; i++) {
			int hs, ws, hb, wb;
			cin >> hs >> ws >> hb >> wb;
			cout << preS[hb-1][wb-1] - preS[hs][wb-1] - preS[hb-1][ws] + preS[hs][ws] << '\n';
		}
		
	}
	return 0;
}
