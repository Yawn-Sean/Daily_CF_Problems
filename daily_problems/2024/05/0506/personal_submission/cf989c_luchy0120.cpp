#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
using namespace std;

void dr(vector<pair<int,char>> v) {
	for (int k = 0;k < 4;++k) {
		for (int i = 0;i < 10;++i) {
			for (int j = 0;j < 50;++j) {
				if (i&1 && (j&1) == 0 && v[k].first > 0) {
					cout << v[k].second;
					v[k].first--;
				}
				else {
					cout << v[(k+1)%4].second;
				}
			}
			cout << endl;
		}
	}
}


int main() {
	int a, b, c, d;cin >> a >> b >> c >> d;
	a--;b--;c--;d--;
	cout << 40 << " " << 50 << endl;
	dr({{ a, 'A' }, { b, 'B' }, {c, 'C'}, {d, 'D'} });

	return 0;
}