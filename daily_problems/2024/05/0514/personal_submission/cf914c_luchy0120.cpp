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
	string n;cin >> n;
	int k; cin >> k;

	if (k == 0) {
		cout << 1;
		return 0;
	}

	int sz = n.size();
	long long s = 0;
	long long mod = 1e9 + 7;

	vector<vector<long long>> c(sz+1, vector <long long>(sz+1, 0 ) );
	c[0][0] = 1;
	for (int j = 1;j <= sz;++j) {
		c[j][0] = 1;
		for (int k = 1;k <= j;++k) {
			c[j][k] = c[j - 1][k] + c[j - 1][k - 1];
			c[j][k] %= mod;
		}
	}



	for (int i = 1;i <= sz;++i) {
		int r = 1;
		int num = i;
		while (num != 1) {
			r++;
			int ct = 0;
			for (int j = 0;j <= 10;++j) {
				if (num >> j & 1) {
					ct++;
				}
			}
			num = ct;
		}
		if (r == k) {
			int tot = 0;
			for (int h = 0;h < sz;++h) {
				if (n[h] == '0') {
					continue;
				}
				// use 0
				s += c[sz - (h + 1)][i - tot];
				s %= mod;
				tot++;
				if (tot == i) {
					s++;
					s %= mod;
					break;
				}
			}
			if (k == 1) {
				s += mod-1;
				s %= mod;
			}


		}
	}
	cout << s << endl;




	




	return 0;
}