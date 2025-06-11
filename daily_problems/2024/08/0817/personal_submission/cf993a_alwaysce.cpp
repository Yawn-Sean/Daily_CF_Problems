#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(false);

    vector<int> s1(8), s2(8);
    for (auto& v: s1) { std::cin >> v; }
    for (auto& v: s2) { std::cin >> v; }

	auto check = [&](vector<int>& square1, vector<int>& square2) {
		int xl = 100, xr = -100, yl = 100, yr = -100;
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 1) {
				yl = min(yl, square2[i]);
				yr = max(yr, square2[i]);
			} else {
				xl = min(xl, square2[i]);
				xr = max(xr, square2[i]);
			}
		}
		for (int i = 0; i < 8; i += 2) {
			if (square1[i] >= xl and square1[i] <= xr and square1[i + 1] >= yl and square1[i + 1] <= yr) {
				return true;
			}
		}
		return square1[0] + square1[4] >= xl * 2
		and square1[0] + square1[4] <= xr * 2
		and square1[1] + square1[5] >= yl * 2 
		and square1[1] + square1[5] <= yr * 2;
	};
	
	if (check(s2, s1)) {
		cout << "YES\n";
	} else {
		// 两个正方形同时旋转45度
		for (int i = 0; i < 8; i += 2) {
			s1[i] += s1[i + 1]; // x + y
			s1[i + 1] = (s1[i] - 2 * s1[i + 1]); // x - y
			s2[i] += s2[i + 1];
			s2[i + 1] = (s2[i] - 2 * s2[i + 1]);
		}
		cout << (check(s1, s2) ? "YES\n": "NO\n");
	}
    return 0;   
}
