#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
#include <queue>
using namespace std;



int main() {
	int n; cin >> n;
	int mx = 1e9 + 7;
	vector<array<int, 4>> pts(n+2);
	pts[0] = { -mx,mx, -mx, mx};
	pts[n+1] = { -mx,mx, -mx,mx};

	for (int i = 1;i <= n;++i) {
		int x;int y;cin >> x >> y;
		int x1; int y1;cin >> x1 >> y1;
		pts[i] = { x,x1,y,y1 };
	}


	auto left = pts;
	
	for (int i = 1;i <= n;++i) {
		left[i][0] = max(left[i][0], left[i-1][0]);
		left[i][1] = min(left[i][1], left[i-1][1]);
		left[i][2] = max(left[i][2], left[i-1][2]);
		left[i][3] = min(left[i][3], left[i-1][3]);
	}

	if (left[n - 1][0] <= left[n - 1][1] && left[n - 1][2] <= left[n - 1][3]) {
		cout << left[n - 1][0] << " " << left[n - 1][2];
		return 0;
	}
	
	auto right = pts;

	for (int i = n;i >= 1 ; --i) {
		auto& left = right;
		left[i][0] = max(left[i][0], left[i + 1][0]);
		left[i][1] = min(left[i][1], left[i + 1][1]);
		left[i][2] = max(left[i][2], left[i + 1][2]);
		left[i][3] = min(left[i][3], left[i + 1][3]);
	}

	if (right[2][0] <= right[2][1] && right[2][2] <= right[2][3]) {
		cout << right[2][0] << " " << right[2][2];
		return 0;
	}


	for (int i = n;i >= 1; --i) {
		int x = max(right[i + 1][0], left[i - 1][0]);
		int x1 = min(right[i + 1][1], left[i - 1][1]);
		int y = max(right[i + 1][2], left[i - 1][2]);
		int y1 = min(right[i + 1][3], left[i - 1][3]);

		if (x <= x1 && y <= y1) {
			cout << x << " " << y << endl;
			return 0;
		}
	}


	return 0;
}