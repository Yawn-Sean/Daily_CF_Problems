#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	
	int t;cin >> t;
	
	for (int i = 0;i < t;++i) {
		int n; cin >> n;
		unordered_map<int, int> mp;
		for (int j = 0;j < n;++j) {
			int c;cin >> c;
			mp[c]++;
		}
		int r = n;
		for (auto& ele : mp) {
			r = min(ele.second,r);
		}
		int res = n;
		for (int j = r + 1;j > 1;--j) {
			int s = 0;
			int ok = 1;
			for (auto& ele : mp) {
				int v = ele.second;
				if (v % j == 0) {
					s += v / j;
				}
				else {
					int y = j - (v % j);
					int xy = (v + j - 1) / j;
					if (xy >= y) {
						s += xy;
					}
					else {
						ok = 0;
						break;
					}
				}
			}
			if (ok) {
				res = s;
				break;
			}

		}
		cout << res << endl;

	}

	return 0;
}