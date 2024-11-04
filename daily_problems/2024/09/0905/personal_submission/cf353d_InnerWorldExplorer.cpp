#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;

	cin >> s;
	int cnt = 0, ans = 0;
	for (char c : s){
		if (c == 'M') cnt ++;
		else if (cnt) ans = max(ans + 1, cnt);
	}
	cout << ans << endl;
	return 0;
}
