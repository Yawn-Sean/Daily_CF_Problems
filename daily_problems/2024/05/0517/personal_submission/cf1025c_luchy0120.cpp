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
	vector<array<int, 2>> v(s.size());
	if (s[0] == 'w') {
		v[0][0] = 1;
	}
	else {
		v[0][1] = 1;
	}
	int r = 1;
	for (int i = 1;i < s.size();++i) {
		int c = (s[i] == 'w') ? 0 : 1;

		v[i][c] = 1;
		if (s[i - 1] != s[i]) {
			v[i][c] += v[i - 1][1 - c];
		}
		r = max(r, v[i][c]);
	}
	reverse(s.begin(),s.end());
	vector<array<int, 2>> v1(s.size());
	if (s[0] == 'w') {
		v1[0][0] = 1;
	}
	else {
		v1[0][1] = 1;
	}
	for (int i = 1;i < s.size();++i) {
		int c = s[i] == 'w' ? 0 : 1;
		v1[i][c] = 1;
		if (s[i - 1] != s[i]) {
			v1[i][c] += v1[i - 1][1 - c];
		}
	}
	if (s[0] != s[s.size() - 1]) {
		int c = s[s.size()-1] == 'w' ? 0 : 1;
		r = max(r, v[s.size() - 1][1-c] + v1[s.size() - 1][c]);
		r = min<int>(r, s.size());
	}
	cout << r;

	






	return 0;
}