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
using namespace std;


int main() {
	int t;cin >> t;
	for (int i = 0;i < t;++i) {
		int n;cin >> n;
		string s;cin >> s;
		long long x = 1;
		long long y = 1;


		for (char c : s) {
			if (c == 'D') {
				x++;
			}
			else {
				y++;
			}
		}
		long long tot = 0;
		if (s[0] == 'D') {
			tot = s.size()+1 + (n - x) * y;
			if (y > 1) {
				int pos = s.find('R');
				tot += (n - y) * (n-pos);
			}
		}
		else {
			tot = s.size()+ 1 + (n - y) * x;
			if (x > 1) {
				int pos = s.find('D');
				tot += (n - x) * (n-pos);
			}
		}
		cout << tot << endl;


	}

	return 0;
}