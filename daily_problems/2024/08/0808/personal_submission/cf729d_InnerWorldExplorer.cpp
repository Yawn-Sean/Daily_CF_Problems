#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;
	s += '1';
	int cnt = 0;
	int t = 0;
	vector<int> ans;
	for (int i = 0; i < (int)(s.size()); i ++){
		char c = s[i];
		if (c == '0'){
			cnt ++;
			if (cnt % b == 0){
				ans.push_back(i);
			}
		}else{
			t += cnt / b;
			cnt = 0;
		}
	}
	int res = t - a + 1;
	cout << res << endl;
	for (int i = 0; i < res; i ++){
		cout << ans[i] + 1 << " \n"[i == res - 1];
	}
	return 0;
}
