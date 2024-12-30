#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 3e5 + 5;

int p[2][N], tt[2] = {-1, -1}, hh[2];
ll ans;
string s;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	
	for(int r = 0, l = -1; r < s.length(); ++ r) {
		int i = s[r] - '0';
		while(hh[i] <= tt[i] && p[i][hh[i]] * 2 - r < max(0, l + 1)) ++ hh[i];
		for(int j = tt[i]; j >= hh[i]; -- j) {
			if(s[p[i][j] * 2 - r] == s[r]) {
				l = max(l, p[i][j] * 2 - r);
				break;
			}
		}
		p[i][++ tt[i]] = r;
		ans += l + 1;
	}
	cout << ans;
	return 0;
}
