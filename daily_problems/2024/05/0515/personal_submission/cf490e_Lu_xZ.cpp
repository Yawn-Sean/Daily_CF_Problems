#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 5;

int pw[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int a[N];
string s[N];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> s[i];
		for(int j = 0; j < s[i].length(); ++ j) {
			if(s[i][j] != '?') {
				a[i] += pw[s[i].length() - j - 1] * (s[i][j] - '0');
			}
		}
	}
	a[n + 1] = 2e9;
	
	for(int i = n; i >= 1; -- i) {
		int m = s[i].length();
		for(int j = 0; j < m; ++ j) {
			if(s[i][j] == '?') {
				for(int k = 9; k >= (j == 0); -- k) {
					if(a[i] + k * pw[m - j - 1] < a[i + 1] || (k == (j == 0))) {
						a[i] += k * pw[m - j - 1];
						break;
					}
				}
			}
		}
		if(a[i] >= a[i + 1]) {
			cout << "NO";
			exit(0);
		}
	}

	cout << "YES\n";
	for(int i = 1; i <= n; ++ i) cout << a[i] << '\n';
	return 0;
}
