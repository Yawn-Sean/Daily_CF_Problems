#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int q;
	cin >> q;
	int n = (int)s.size();
	int pre[26][n + 1];
	memset(pre, 0, sizeof pre);
	for (int i = 0; i < (int)s.size(); i ++){
		for (int j = 0; j < 26; j ++){
			pre[j][i + 1] = pre[j][i];
			if (j == s[i] - 'a'){
				pre[j][i + 1] = pre[j][i] + 1;
			}
		}
	}
	int l, r;
	while (q -- ) {
		cin >> l >> r;
		if (l == r) {
			cout << "Yes" << endl;
		} else {
			l --; r --;
			int cnt = 0;
			for (int i = 0; i < 26; i ++){
				cnt += (pre[i][r + 1] - pre[i][l] > 0);
			}
			cout << (cnt <= 2 && s[l] == s[r] ? "No" : "Yes") << endl;
		}
	}
	return 0;
}
