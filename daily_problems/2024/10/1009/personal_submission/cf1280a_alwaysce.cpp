#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		int x;
		string s;
		cin >> x >> s;
		
		int k = s.size(), npt = min(k, x);
		vector<int> tmp(x);
		
		for (int i = 0; i < npt; i++) {
			tmp[i] = s[i] - '0';
		}
		
		i64 cur_len = k;
		for (int pt = 0; pt < x; pt++) {
			// s[left] + s[right] * (s[l])次重复
			cur_len += (cur_len - pt - 1) * (tmp[pt] - 1) % mod;
			cur_len %= mod;
			cur_len = (cur_len + mod) % mod;
			
			int p = pt + 1, e = npt, c = 1;
			// 总操作次数是 x 暴力模拟tmp[pt]次操作
			while (c < tmp[pt] and npt < x) {
				tmp[npt] = tmp[p];
				npt++;
				p++;
				// s[right]操作了一整条
				if (p == e) {
					p = pt + 1;
					c++;
				}
			}
		}
		cout << cur_len << '\n';
	}
	return 0;
}
