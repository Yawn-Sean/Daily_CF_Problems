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
	string s;cin >> s;
	
	vector<array<int, 2>> v;

	for (int i = 0;i < s.size();++i) {
		int j = i;
		while (j < s.size() && s[j] == s[i]) {
			j++;
		}
		v.push_back({ s[i] - 'a',j - i });
		i = j - 1;
	}
	int tm = 0;
	while (v.size() > 1) {
		vector<array<int, 2>> c;
		if (v[0][1] > 1) {
			c.push_back({v[0][0],v[0][1]-1});
		}
		for (int j = 1;j < v.size();++j) {
			int g = 2;
			if (j == v.size() - 1) {
				g = 1;
			}
			if (v[j][1] - g > 0) {
				c.push_back({v[j][0], v[j][1] - g});
			}
		}
		vector<array<int, 2>> cc;
		for (int j = 0;j < c.size();++j) {
			if (cc.size() > 0) {
				if (cc.back()[0] != c[j][0]) {
					cc.push_back(c[j]);
				}
				else {
					cc.back()[1] += c[j][1];
				}
			}
			else {
				cc.push_back(c[j]);
			}

		}
		swap(cc, v);
		tm++;
	}
	cout << tm;


	






	return 0;
}