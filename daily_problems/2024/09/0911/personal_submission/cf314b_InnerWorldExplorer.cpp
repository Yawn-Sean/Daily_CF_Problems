#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int b, d;
	string a, c;
	cin >> b >> d >> a >> c;

	int n = (int) c.size();
	vector<int> pos(n), cnt(n);
	iota(pos.begin(), pos.end(), 0);

	for (int i = 0; i < n; i ++){
		for (char &ch : a){
			if (ch == c[pos[i]]){
				pos[i] ++;
				if (pos[i] == n){
					pos[i] = 0;
					cnt[i] ++;
				}
			}
		}
	}

	int ans = 0, i = 0;
	while (b -- ){
		ans += cnt[i];
		i = pos[i];
	}
	cout << ans / d << endl;
	return 0;
}
