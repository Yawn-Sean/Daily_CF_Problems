#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s, t;
	cin >> s >> t;
	int n = s.size();
	
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			bool find = false;
			for (int j = i + 1; j < n; j++) {
				if (s[j] != 'z') {
					find = true;
				}
			}
			
			if (find) {
				cout << s.substr(0, i + 1) << string(n - i - 1, 'z');
			} else {
				string ans = s.substr(0, i) + (char)(s[i]+1) + string(n - i - 1, 'a');
				cout << (ans < t ? ans : "No such string");
			}
			return 0;
		}
	}

	return 0;
}
