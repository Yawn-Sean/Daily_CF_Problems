#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	string s; cin >> s;
	int n = s.length();
	s = s + s;
	int ans = 0;
	for(int i = 0, j = 0; i < 2 * n; ++ i) {
		if(i && s[i] == s[i - 1]) {
			j = i;
		}
		while(j < i && i - j >= n) ++ j;
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
