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
	int n;cin >> n;
	string s, t;cin >> s >> t;

	int f = 0;
	while (s[f] == t[f]) {
		f++;
	}
	int e = n-1;
	while (s[e] == t[e]) {
		e--;
	}
	if (f != e) {
		int r = s.substr(f, e - f) == t.substr(f + 1, e - f);
		r += t.substr(f, e - f) == s.substr(f + 1, e - f);
		cout << r;
		return 0;
	}
	else {
		cout << 2;

	}
	










	return 0;
}