#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int idx;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == 'e') {
			idx = i;
		}
	}

	long double v1 = stold(s.substr(0, idx));
	int v2 = stoll(s.substr(idx + 2));

	while (n --) {
		v1 *= 1.5 - 2 * powl(v1 * powl(0.1, v2), 2);
		while (abs(v1) >= 10) {
			v1 /= 10;
			v2 --;
		}
	}

	cout << fixed << setprecision(20) << 0.5 + v1 * powl(0.1, v2);

	return 0;
}